# HARM Overview

This repository contains the HARM general relativistic radiation magnetohydrodynamics
(GRRMHD) code.  The tree is large, but the main build system is driven by the
`makefile` in the project root.

## Building

1. Edit `makehead.inc` to choose compilers and system options.  The file
   contains many predefined setups that key off of `$HOSTNAME`.
2. Run the normal compile sequence:

   ```bash
   make superclean
   make prep
   make -j N    # where N is the number of build threads
   ```

   This produces the `grmhd` executable.  Example commands appear in the
   installation notes and quick start guide, e.g.
   `make superclean ; make prep ; make -j 16`.

3. Create a run directory and copy the binary there:

   ```bash
   mkdir run
   cp grmhd run/
   cd run
   ```

4. Execute the code either directly or through MPI.  With OpenMP+MPI enabled, run
   `nohup ./grmhd 4 1 1 1 &` as shown in the quick start guide.  If MPI and
   OpenMP are disabled, run `nohup ./grmhd &`.

Batch submission scripts for large runs are located under `batches/`.  These
include examples for systems such as Stampede and Kraken.

## Important Directories

- `batches/` – example batch files for supercomputer queues.
- `docs/` – assorted documentation including installation instructions.
- `environmentfiles/` – template shell setups for various machines.
- `initboundcode/` – initialization and boundary condition routines.
- `initbounddata/` – data files used by the initializers.
- `scripts/` – helper scripts for building and post‑processing.
- `utils/` and `r8toras/` – utility programs for data conversion and analysis.

## Selecting a Problem Setup

Problem specific options live in `init.h`.  Near the middle of this file a block
of `#define WHICHPROBLEM ...` statements lists all available problems.  Only one
should be active at a time.  For example, the default is

```c
#define WHICHPROBLEM RADDONUT
```

Change this line to another value, or comment/uncomment one of the other
options, to select a different initial setup.  Each problem also defines its own
values of `N1`, `N2`, and `N3` which control the per‑core resolution.

## RADDONUT Setup

`RADDONUT` describes a radiative thick torus (“Polish doughnut”) in Kerr–Schild
coordinates.  The parameters for this case are defined in `init.h` around
lines 1057–1087.  By default the grid uses `N1=N2=N3=8`, thermal Comptonization
is enabled and several optimizations (`DOPERF`, `BORROWENTROPY`) are turned on.
Additional notes about tuning the resolution appear in `docs/stampede.txt`.

## Running Simulations

After compiling and selecting a problem, run the executable from a run
subdirectory.  For quick tests use the local command mentioned above.  For large
simulations copy an appropriate script from `batches/` and submit it through the
queue system, e.g.

```bash
sbatch batch.slurm.kraken.radtma0.8a
```

This runs the code with the parameters specified in the batch file.  Results and
post‑processing scripts reside under `runresults/` and `scripts/`.

