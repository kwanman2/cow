
/*! \file bounds.tools.c
  \brief General or frequenty-used Boundary condition routines

  // Typically these are only called by user code bounds.c

*/

/*! \file bounds.c
  \brief USER boundary condition routines (often calling things in bounds.tools.c)
*/

#include "decs.h"

// see definit.h or init.h for some defines here.


/// X1DN FIXEDUSINGPANALYTIC
///
///////////////////////////
/// Currently assume completely general situation where 
/// only triggers on BCs, but across all CPUs.  Use grid sectioning to enforce per-CPU dependence if desired.  Any other CPUs that have BCs set will have BCs overwritten by MPI routines
/// SUPERGODMARK: Should be able to use set_boundloop()'s result if included FIXED version, but currently it only handles OUTFLOW types for grid sectioning
int bound_x1dn_analytic(int boundstage, int finalstep, SFTYPE boundtime, int whichdir, int boundvartype, int *dirprim, int ispstag, FTYPE (*prim)[NSTORE2][NSTORE3][NPR])
{
  int i,j,k;
  int pl,pliter;

#if(ANALYTICMEMORY==0)
  dualfprintf(fail_file,"ANALYTICMEMORY==0 but called bound_x1dn_analytic\n");
  myexit(786752);
#endif


  // then no need to set pglobal or pstagglobal since evolution sets appropriately in constrained way on a well-defined computational box
  //  dualfprintf(fail_file,"No use for this currently\n");
  //  myexit(34269834);



  if(ispstag){
    COMPFULLLOOP{
      // note we assume "i=0" is boundary cell to be fixed
      // This ensures divb=0, but may be inconsistent with code's treatement of true i=0 if doing OUTFLOW
      if(WITHINACTIVESTAGBNDSECTIONX1DN(i,j,k)){
        pl=B1; MACP0A1(prim,i,j,k,pl) = GLOBALMACP0A1(pstaganalytic,i,j,k,pl);
      }
      if(WITHINACTIVEBNDSECTIONX1DN(i,j,k)){
        PBOUNDLOOP(pliter,pl) if(pl!=B1) MACP0A1(prim,i,j,k,pl) = GLOBALMACP0A1(pstaganalytic,i,j,k,pl);
      }
    }
  }
  else{
    COMPFULLLOOP{
      if(WITHINACTIVEBNDSECTIONX1DN(i,j,k)){
        PBOUNDLOOP(pliter,pl) MACP0A1(prim,i,j,k,pl) = GLOBALMACP0A1(panalytic,i,j,k,pl);
      }
    }
 
  }


  return(0);
}


/// X1UP FIXEDUSINGPANALYTIC
///
////////////////////////////
/// Currently assume completely general situation where 
/// only triggers on BCs, but across all CPUs.  Use grid sectioning to enforce per-CPU dependence if desired.  Any other CPUs that have BCs set will have BCs overwritten by MPI routines
/// SUPERGODMARK: Should be able to use set_boundloop()'s result if included FIXED version, but currently it only handles OUTFLOW types for grid sectioning
int bound_x1up_analytic(int boundstage, int finalstep, SFTYPE boundtime, int whichdir, int boundvartype, int *dirprim, int ispstag, FTYPE (*prim)[NSTORE2][NSTORE3][NPR])
{
  int i,j,k;
  int pl,pliter;


#if(ANALYTICMEMORY==0)
  dualfprintf(fail_file,"ANALYTICMEMORY==0 but called bound_x1up_analytic\n");
  myexit(786753);
#endif


  // KORALTODO: Check below
  // then no need to set pglobal or pstagglobal since evolution sets appropriately in constrained way on a well-defined computational box
  //  dualfprintf(fail_file,"No use for this currently\n");
  //  myexit(34269834);


  if(ispstag){
    COMPFULLLOOP{
      if(WITHINACTIVESTAGBNDSECTIONX1UP(i,j,k)){
        pl=B1; MACP0A1(prim,i,j,k,pl) = GLOBALMACP0A1(pstaganalytic,i,j,k,pl);
      }
      if(WITHINACTIVEBNDSECTIONX1UP(i,j,k)){
        PBOUNDLOOP(pliter,pl) if(pl!=B1) MACP0A1(prim,i,j,k,pl) = GLOBALMACP0A1(pstaganalytic,i,j,k,pl);
      }
    }
  }
  else{
    COMPFULLLOOP{
      if(WITHINACTIVEBNDSECTIONX1UP(i,j,k)){
        PBOUNDLOOP(pliter,pl) MACP0A1(prim,i,j,k,pl) = GLOBALMACP0A1(panalytic,i,j,k,pl);
      }
    }
 
  }


  return(0);
}


/// X2DN FIXEDUSINGPANALYTIC
///
////////////////////////////
/// Currently assume completely general situation where 
/// only triggers on BCs, but across all CPUs.  Use grid sectioning to enforce per-CPU dependence if desired.  Any other CPUs that have BCs set will have BCs overwritten by MPI routines
/// SUPERGODMARK: Should be able to use set_boundloop()'s result if included FIXED version, but currently it only handles OUTFLOW types for grid sectioning
int bound_x2dn_analytic(int boundstage, int finalstep, SFTYPE boundtime, int whichdir, int boundvartype, int *dirprim, int ispstag, FTYPE (*prim)[NSTORE2][NSTORE3][NPR])
{
  int i,j,k;
  int pl,pliter;

#if(ANALYTICMEMORY==0)
  dualfprintf(fail_file,"ANALYTICMEMORY==0 but called bound_x2dn_analytic\n");
  myexit(786752);
#endif


  // KORALTODO: Check if below true.
  // then no need to set pglobal or pstagglobal since evolution sets appropriately in constrained way on a well-defined computational box
  //  dualfprintf(fail_file,"No use for this currently\n");
  //  myexit(34269834);



  if(ispstag){
    COMPFULLLOOP{
      // note we assume "j=0" is boundary cell to be fixed
      // This ensures divb=0, but may be inconsistent with code's treatement of true j=0 if doing OUTFLOW
      if(WITHINACTIVESTAGBNDSECTIONX2DN(i,j,k)){
        pl=B2; MACP0A1(prim,i,j,k,pl) = GLOBALMACP0A1(pstaganalytic,i,j,k,pl);
      }
      if(WITHINACTIVEBNDSECTIONX2DN(i,j,k)){
        PBOUNDLOOP(pliter,pl) if(pl!=B2) MACP0A1(prim,i,j,k,pl) = GLOBALMACP0A1(pstaganalytic,i,j,k,pl);
      }
    }
  }
  else{
    COMPFULLLOOP{
      if(WITHINACTIVEBNDSECTIONX2DN(i,j,k)){
        PBOUNDLOOP(pliter,pl) MACP0A1(prim,i,j,k,pl) = GLOBALMACP0A1(panalytic,i,j,k,pl);
      }
    }
 
  }


  return(0);
}


/// X2UP FIXEDUSINGPANALYTIC
///
////////////////////////////
/// Currently assume completely general situation where 
/// only triggers on BCs, but across all CPUs.  Use grid sectioning to enforce per-CPU dependence if desired.  Any other CPUs that have BCs set will have BCs overwritten by MPI routines
/// SUPERGODMARK: Should be able to use set_boundloop()'s result if included FIXED version, but currently it only handles OUTFLOW types for grid sectioning
int bound_x2up_analytic(int boundstage, int finalstep, SFTYPE boundtime, int whichdir, int boundvartype, int *dirprim, int ispstag, FTYPE (*prim)[NSTORE2][NSTORE3][NPR])
{
  int i,j,k;
  int pl,pliter;


#if(ANALYTICMEMORY==0)
  dualfprintf(fail_file,"ANALYTICMEMORY==0 but called bound_x2up_analytic\n");
  myexit(786753);
#endif



  // then no need to set pglobal or pstagglobal since evolution sets appropriately in constrained way on a well-defined computational box
  //  dualfprintf(fail_file,"No use for this currently\n");
  //  myexit(34269834);


  if(ispstag){
    COMPFULLLOOP{
      if(WITHINACTIVESTAGBNDSECTIONX2UP(i,j,k)){
        pl=B2; MACP0A1(prim,i,j,k,pl) = GLOBALMACP0A1(pstaganalytic,i,j,k,pl);
      }
      if(WITHINACTIVEBNDSECTIONX2UP(i,j,k)){
        PBOUNDLOOP(pliter,pl) if(pl!=B2) MACP0A1(prim,i,j,k,pl) = GLOBALMACP0A1(pstaganalytic,i,j,k,pl);
      }
    }
  }
  else{
    COMPFULLLOOP{
      if(WITHINACTIVEBNDSECTIONX2UP(i,j,k)){
        PBOUNDLOOP(pliter,pl) MACP0A1(prim,i,j,k,pl) = GLOBALMACP0A1(panalytic,i,j,k,pl);
      }
    }
 
  }


  return(0);
}



/// X3DN FIXEDUSINGPANALYTIC
///
////////////////////////////
/// Currently assume completely general situation where 
/// only triggers on BCs, but across all CPUs.  Use grid sectioning to enforce per-CPU dependence if desired.  Any other CPUs that have BCs set will have BCs overwritten by MPI routines
/// SUPERGODMARK: Should be able to use set_boundloop()'s result if included FIXED version, but currently it only handles OUTFLOW types for grid sectioning
int bound_x3dn_analytic(int boundstage, int finalstep, SFTYPE boundtime, int whichdir, int boundvartype, int *dirprim, int ispstag, FTYPE (*prim)[NSTORE2][NSTORE3][NPR])
{
  int i,j,k;
  int pl,pliter;

#if(ANALYTICMEMORY==0)
  dualfprintf(fail_file,"ANALYTICMEMORY==0 but called bound_x3dn_analytic\n");
  myexit(786752);
#endif


  // KORALTODO: Check if below true.
  // then no need to set pglobal or pstagglobal since evolution sets appropriately in constrained way on a well-defined computational box
  //  dualfprintf(fail_file,"No use for this currently\n");
  //  myexit(34269834);



  if(ispstag){
    COMPFULLLOOP{
      // note we assume "k=0" is boundary cell to be fixed
      // This ensures divb=0, but may be inconsistent with code's treatement of true k=0 if doing OUTFLOW
      if(WITHINACTIVESTAGBNDSECTIONX3DN(i,j,k)){
        pl=B3; MACP0A1(prim,i,j,k,pl) = GLOBALMACP0A1(pstaganalytic,i,j,k,pl);
      }
      if(WITHINACTIVEBNDSECTIONX3DN(i,j,k)){
        PBOUNDLOOP(pliter,pl) if(pl!=B3) MACP0A1(prim,i,j,k,pl) = GLOBALMACP0A1(pstaganalytic,i,j,k,pl);
      }
    }
  }
  else{
    COMPFULLLOOP{
      if(WITHINACTIVEBNDSECTIONX3DN(i,j,k)){
        PBOUNDLOOP(pliter,pl) MACP0A1(prim,i,j,k,pl) = GLOBALMACP0A1(panalytic,i,j,k,pl);
      }
    }
 
  }


  return(0);
}


/// X3UP FIXEDUSINGPANALYTIC
///
////////////////////////////
/// Currently assume completely general situation where 
/// only triggers on BCs, but across all CPUs.  Use grid sectioning to enforce per-CPU dependence if desired.  Any other CPUs that have BCs set will have BCs overwritten by MPI routines
/// SUPERGODMARK: Should be able to use set_boundloop()'s result if included FIXED version, but currently it only handles OUTFLOW types for grid sectioning
int bound_x3up_analytic(int boundstage, int finalstep, SFTYPE boundtime, int whichdir, int boundvartype, int *dirprim, int ispstag, FTYPE (*prim)[NSTORE2][NSTORE3][NPR])
{
  int i,j,k;
  int pl,pliter;


#if(ANALYTICMEMORY==0)
  dualfprintf(fail_file,"ANALYTICMEMORY==0 but called bound_x3up_analytic\n");
  myexit(786753);
#endif



  // then no need to set pglobal or pstagglobal since evolution sets appropriately in constrained way on a well-defined computational box
  //  dualfprintf(fail_file,"No use for this currently\n");
  //  myexit(34269834);


  if(ispstag){
    COMPFULLLOOP{
      if(WITHINACTIVESTAGBNDSECTIONX3UP(i,j,k)){
        pl=B3; MACP0A1(prim,i,j,k,pl) = GLOBALMACP0A1(pstaganalytic,i,j,k,pl);
      }
      if(WITHINACTIVEBNDSECTIONX3UP(i,j,k)){
        PBOUNDLOOP(pliter,pl) if(pl!=B3) MACP0A1(prim,i,j,k,pl) = GLOBALMACP0A1(pstaganalytic,i,j,k,pl);
      }
    }
  }
  else{
    COMPFULLLOOP{
      if(WITHINACTIVEBNDSECTIONX3UP(i,j,k)){
        PBOUNDLOOP(pliter,pl) MACP0A1(prim,i,j,k,pl) = GLOBALMACP0A1(panalytic,i,j,k,pl);
      }
    }
 
  }


  return(0);
}



/// X1 inner OUTFLOW/FIXEDOUTFLOW
int bound_x1dn_outflow_simple(
                              int boundstage, int finalstep, SFTYPE boundtime, int whichdir, int boundvartype, int *dirprim, int ispstag, FTYPE (*prim)[NSTORE2][NSTORE3][NPR],
                              int *inboundloop,
                              int *outboundloop,
                              int *innormalloop,
                              int *outnormalloop,
                              int (*inoutlohi)[NUMUPDOWN][NDIM],
                              int riin, int riout, int rjin, int rjout, int rkin, int rkout,
                              int *dosetbc,
                              int enerregion,
                              int *localenerpos
                              )
{



#pragma omp parallel  // assume don't require EOS
  {
    int i,j,k,pl,pliter;
    struct of_geom geom[NPR],rgeom[NPR];
    FTYPE vcon[NDIM]; // coordinate basis vcon
#if(WHICHVEL==VEL3)
    int failreturn;
#endif
    int ri, rj, rk; // reference i,j,k
    FTYPE prescale[NPR];
    int jj,kk;
    struct of_geom geomdontuse[NPR];
    struct of_geom *ptrgeom[NPR];
    struct of_geom rgeomdontuse[NPR];
    struct of_geom *ptrrgeom[NPR];


    // assign memory
    PALLLOOP(pl){
      ptrgeom[pl]=&(geomdontuse[pl]);
      ptrrgeom[pl]=&(rgeomdontuse[pl]);
    }


    if(((BCtype[X1DN]==OUTFLOW || BCtype[X1DN]==HORIZONOUTFLOW))||(BCtype[X1DN]==FIXEDOUTFLOW)||(BCtype[X1DN]==FREEOUTFLOW)){


      if ( (totalsize[1]>1) && (mycpupos[1] <= 0)) {
        /* inner r boundary condition: u, just copy */

        //        PBOUNDLOOP(pliter,pl) dualfprintf(fail_file,"WTF1A: pl=%d pliter=%d : %d %d %d : nstep=%ld %d %g\n",pl,pliter,nprboundstart,nprboundend,nprboundlist[pliter],nstep,steppart,t);
        //        dualfprintf(fail_file,"WTF1A: ri=%d loopin=%d %d\n",riin,inoutlohi[POINTDOWN][POINTDOWN][1],inoutlohi[POINTDOWN][POINTUP][1]);


        OPENMPBCLOOPVARSDEFINELOOPX1DIR; OPENMPBCLOOPSETUPLOOPX1DIR;
        //////// LOOPX1dir{
#pragma omp for schedule(OPENMPSCHEDULE(),OPENMPCHUNKSIZE(blocksize))
        OPENMPBCLOOPBLOCK{
          OPENMPBCLOOPBLOCK2IJKLOOPX1DIR(j,k);



          ri=riin;
          rj=j;
          rk=k;


          PALLLOOP(pl) get_geometry(ri, rj, rk, dirprim[pl], ptrrgeom[pl]);

          LOOPBOUND1IN{ // bound entire region inside non-evolved portion of grid
            PBOUNDLOOP(pliter,pl) MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj,rk,pl);
            //if(MACP0A1(prim,i,j,k,URAD1)>=0.0) MACP0A1(prim,i,j,k,URAD1)=0.0;
          }




          if(ispstag==0){

            if(((BCtype[X1DN]==OUTFLOW || BCtype[X1DN]==HORIZONOUTFLOW))||(BCtype[X1DN]==FIXEDOUTFLOW)){
              // GODMARK: assume all velocities at same location when doing inflow check
              LOOPBOUND1INSPECIAL{
#if(WHICHVEL==VEL4)
                get_geometry(i, j, k, dirprim[U1], ptrgeom[U1]);
                inflow_check_4vel(1,MAC(prim,i,j,k),NULL,ptrgeom[U1], 0) ;
#elif(WHICHVEL==VEL3)
                get_geometry(i, j, k, dirprim[U1], ptrgeom[U1]);
                inflow_check_3vel(1,MAC(prim,i,j,k),NULL,ptrgeom[U1], 0) ;
                // projection may not preserve u^t to be real and rho>rhoscal u>uuscal
#if(JONCHECKS)
                if(jonchecks){
                  //fixup1zone(0,MAC(prim,i,j,k),ptrgeom[U1],0);
                  failreturn=check_pr(MAC(prim,i,j,k),MAC(prim,i,j,k),ptrgeom[U1],-3);
                  if(failreturn){
                    dualfprintf(fail_file,"Bad boundary zone, couldn't fix: i=%d j=%d k=%d\n",startpos[1]+i,startpos[2]+j,startpos[3]+k);
                    if (fail(i,j,k,FAIL_BCFIX) >= 1) return (1);
                  }
                }
#endif
#elif(WHICHVEL==VELREL4)
                get_geometry(i,j,k,dirprim[U1],ptrgeom[U1]) ;
                inflow_check_rel4vel(1,MAC(prim,i,j,k),NULL,ptrgeom[U1],0) ;
                if(limit_gamma(0,GAMMAMAX,GAMMAMAXRAD,MAC(prim,i,j,k),NULL,ptrgeom[U1],0)>=1)
                  FAILSTATEMENT("bounds.c:bound_prim()", "limit_gamma()", 1);
#endif 
              }
            } // end if not allowing inflow
          }


        }// end 2 3

      }// end if mycpupos[1]==0



    }
    else{
      dualfprintf(fail_file,"Shouldn't be here in bounds: dir=%d\n",X1DN);
      myexit(3946836);
    }


  }// end parallel region


  return(0);
}

/// X1 outer OUTFLOW/FIXEDOUTFLOW
int bound_x1up_outflow_simple(
                              int boundstage, int finalstep, SFTYPE boundtime, int whichdir, int boundvartype, int *dirprim, int ispstag, FTYPE (*prim)[NSTORE2][NSTORE3][NPR],
                              int *inboundloop,
                              int *outboundloop,
                              int *innormalloop,
                              int *outnormalloop,
                              int (*inoutlohi)[NUMUPDOWN][NDIM],
                              int riin, int riout, int rjin, int rjout, int rkin, int rkout,
                              int *dosetbc,
                              int enerregion,
                              int *localenerpos
                              )
{




#pragma omp parallel  // assume don't require EOS
  {

    int i,j,k,pl,pliter;
    FTYPE vcon[NDIM]; // coordinate basis vcon
#if(WHICHVEL==VEL3)
    int failreturn;
#endif
    int ri, rj, rk; // reference i,j,k
    FTYPE prescale[NPR];
    int jj,kk;
    struct of_geom geomdontuse[NPR];
    struct of_geom *ptrgeom[NPR];
    struct of_geom rgeomdontuse[NPR];
    struct of_geom *ptrrgeom[NPR];

    // assign memory
    PALLLOOP(pl){
      ptrgeom[pl]=&(geomdontuse[pl]);
      ptrrgeom[pl]=&(rgeomdontuse[pl]);
    }


  
    if(((BCtype[X1UP]==OUTFLOW || BCtype[X1UP]==HORIZONOUTFLOW))||(BCtype[X1UP]==FIXEDOUTFLOW)||(BCtype[X1UP]==FREEOUTFLOW)){

      // outer r BC:
      if ( (totalsize[1]>1) && (mycpupos[1] == ncpux1 - 1) ) {


        //        PBOUNDLOOP(pliter,pl) dualfprintf(fail_file,"WTF2A: pl=%d pliter=%d : %d %d %d : nstep=%ld %d %g\n",pl,pliter,nprboundstart,nprboundend,nprboundlist[pliter],nstep,steppart,t);
        //        dualfprintf(fail_file,"WTF2A: ri=%d loop=%d %d\n",riout,inoutlohi[POINTUP][POINTDOWN][1],inoutlohi[POINTUP][POINTUP][1]);


        OPENMPBCLOOPVARSDEFINELOOPX1DIR; OPENMPBCLOOPSETUPLOOPX1DIR;
        //////// LOOPX1dir{
#pragma omp for schedule(OPENMPSCHEDULE(),OPENMPCHUNKSIZE(blocksize))
        OPENMPBCLOOPBLOCK{
          OPENMPBCLOOPBLOCK2IJKLOOPX1DIR(j,k);


          ri=riout;
          rj=j;
          rk=k;

          PALLLOOP(pl) get_geometry(ri, rj, rk, dirprim[pl], ptrrgeom[pl]);

          LOOPBOUND1OUT PBOUNDLOOP(pliter,pl){
            MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj,rk,pl);
          }





          if(ispstag==0){

            if(((BCtype[X1UP]==OUTFLOW || BCtype[X1UP]==HORIZONOUTFLOW))||(BCtype[X1UP]==FIXEDOUTFLOW)){

              LOOPBOUND1OUT{
#if(WHICHVEL==VEL4)
                get_geometry(i, j, k, dirprim[U1], ptrgeom[U1]);
                inflow_check_4vel(1,MAC(prim,i,j,k),NULL,ptrgeom[U1],0) ;
#elif(WHICHVEL==VEL3)
                get_geometry(i, j, k, dirprim[U1], ptrgeom[U1]);
                inflow_check_3vel(1,MAC(prim,i,j,k),NULL,ptrgeom[U1],0) ;
                // projection may not preserve u^t to be real and rho>rhoscal u>uuscal
#if(JONCHECKS)
                if(jonchecks){
                  //fixup1zone(0,MAC(prim,i,j,k),ptrgeom[U1],0);
                  failreturn=check_pr(MAC(prim,i,j,k),MAC(prim,i,j,k),ptrgeom[U1],-3);
                  if(failreturn){
                    dualfprintf(fail_file,"Bad boundary zone, couldn't fix: i=%d j=%d k=%d\n",startpos[1]+i,startpos[2]+j,startpos[3]+k);
                    if (fail(i,j,k,FAIL_BCFIX) >= 1) return (1);
                  }
                }
#endif
#elif(WHICHVEL==VELREL4)
                get_geometry(i,j,k,dirprim[U1],ptrgeom[U1]) ;
                inflow_check_rel4vel(1,MAC(prim,i,j,k),NULL,ptrgeom[U1],0) ;
                if(limit_gamma(0,GAMMAMAX,GAMMAMAXRAD,MAC(prim,i,j,k),NULL,ptrgeom[U1], 0)>=1)
                  FAILSTATEMENT("bounds.c:bound_prim()", "limit_gamma()", 2);
#endif 
              }// end over i
            }// end if not allowing inflow

          }



        }// end 2 3
      }// end if mycpu is correct

    }
    else{
      dualfprintf(fail_file,"Shouldn't be here in bounds: dir=%d\n",X1UP);
      myexit(3946837);
    }

  }// end parallel region


  return(0);
}
















/// X1 inner OUTFLOW/FIXEDOUTFLOW
int bound_x1dn_outflow(
                       int boundstage, int finalstep, SFTYPE boundtime, int whichdir, int boundvartype, int *dirprim, int ispstag, FTYPE (*prim)[NSTORE2][NSTORE3][NPR],
                       int *inboundloop,
                       int *outboundloop,
                       int *innormalloop,
                       int *outnormalloop,
                       int (*inoutlohi)[NUMUPDOWN][NDIM],
                       int riin, int riout, int rjin, int rjout, int rkin, int rkout,
                       int *dosetbc,
                       int enerregion,
                       int *localenerpos
                       )
{



#pragma omp parallel  // assume don't require EOS
  {
    int i,j,k,pl,pliter;
    struct of_geom geom[NPR],rgeom[NPR];
    FTYPE vcon[NDIM]; // coordinate basis vcon
#if(WHICHVEL==VEL3)
    int failreturn;
#endif
    int ri, rj, rk; // reference i,j,k
    FTYPE prescale[NPR];
    int horizonti;
    int jj,kk;
    struct of_geom geomdontuse[NPR];
    struct of_geom *ptrgeom[NPR];
    struct of_geom rgeomdontuse[NPR];
    struct of_geom *ptrrgeom[NPR];


    // assign memory
    PALLLOOP(pl){
      ptrgeom[pl]=&(geomdontuse[pl]);
      ptrrgeom[pl]=&(rgeomdontuse[pl]);
    }


    if((BCtype[X1DN]==HORIZONOUTFLOW)||(BCtype[X1DN]==OUTFLOW)||(BCtype[X1DN]==FIXEDOUTFLOW)||(BCtype[X1DN]==FREEOUTFLOW)){


      if ( (totalsize[1]>1) && (mycpupos[1] <= horizoncpupos1)) { // now all CPUs inside CPU with horizon will be using this (GODMARK: reference value needs to be chosen somehow for CPUs not on active grid)
        /* inner r boundary condition: u, just copy */

        OPENMPBCLOOPVARSDEFINELOOPX1DIR; OPENMPBCLOOPSETUPLOOPX1DIR;
        //////// LOOPX1dir{
#pragma omp for schedule(OPENMPSCHEDULE(),OPENMPCHUNKSIZE(blocksize))
        OPENMPBCLOOPBLOCK{
          OPENMPBCLOOPBLOCK2IJKLOOPX1DIR(j,k);



          ri=riin;
          rj=j;
          rk=k;


#if(HORIZONEXTRAP==0)
          PALLLOOP(pl) get_geometry(ri, rj, rk, dirprim[pl], ptrrgeom[pl]);

          LOOPBOUND1INSPECIAL{ // bound entire region inside non-evolved portion of grid
            PBOUNDLOOP(pliter,pl) MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj,rk,pl);
          }
#elif(HORIZONEXTRAP==1)
          PALLLOOP(pl) get_geometry(ri, rj, rk, dirprim[pl], ptrrgeom[pl]);

          LOOPBOUND1INSPECIAL{ // bound entire region inside non-evolved portion of grid

            PALLLOOP(pl) get_geometry(i, j, k, dirprim[pl], ptrgeom[pl]);

            PBOUNDLOOP(pliter,pl){
              if(pl>=RHO && pl<=UU){
                MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj,rk,pl) * (ptrrgeom[pl]->gdet/ptrgeom[pl]) ;
              }
            }
            PBOUNDLOOP(pliter,pl){
              if(pl==U1){     // treat U1 as special
                MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj,rk,pl) * (1. - (i-ri)*dx[1]) ;
                for(pl=U2;pl<=U3;pl++){
                  MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj,rk,pl) * (1. + (i-ri)*dx[1]) ;
                }
              }
            }
            PBOUNDLOOP(pliter,pl){
              if(pl==B1){ // treat B1 special
                MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj,rk,pl) * (ptrrgeom[pl]->gdet/ptrgeom[pl]);
                for(pl=B2;pl<=B3;pl++){
                  MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj,rk,pl) * (1. + (i-ri)*dx[1]) ;
                }
              }
            }
            PBOUNDLOOP(pliter,pl){
              if(pl>=B3+1 && pl<NPRBOUND){
                MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj,rk,pl) * (ptrrgeom[pl]->gdet/ptrgeom[pl]);
              }
            }
          }
#elif(HORIZONEXTRAP==2)
          get_geometry(ri, rj, rk, dirprim[0], ptrrgeom[0]);
          rescale(DORESCALE,1,MAC(prim,ri,rj,rk),ptrrgeom[0],prescale);
          LOOPBOUND1INSPECIAL{
            // set guess
            PBOUNDLOOP(pliter,pl) MACP0A1(prim,i,j,k,pl)=MACP0A1(prim,ri,rj,k,pl);
            get_geometry(i, j, k, dirprim[0], ptrgeom[0]);     
            rescale(UNRESCALE,1,MAC(prim,i,j,k),ptrgeom[0],prescale);
          }
#elif(HORIZONEXTRAP==3)
          extrapfunc(X1DN,j,k,boundstage,finalstep,boundtime,whichdir,boundvartype,dirprim,ispstag,prim,inboundloop,outboundloop,innormalloop,outnormalloop,inoutlohi,riin,riout,rjin,rjout,rkin,rkout,dosetbc,enerregion,localenerpos);
#endif




          if(ispstag==0){

            if(((BCtype[X1DN]==OUTFLOW || BCtype[X1DN]==HORIZONOUTFLOW))||(BCtype[X1DN]==FIXEDOUTFLOW)){
              // GODMARK: assume all velocities at same location when doing inflow check
              LOOPBOUND1INSPECIAL{
#if(WHICHVEL==VEL4)
                get_geometry(i, j, k, dirprim[U1], ptrgeom[U1]);
                inflow_check_4vel(1,MAC(prim,i,j,k),NULL,ptrgeom[U1], 0) ;
#elif(WHICHVEL==VEL3)
                get_geometry(i, j, k, dirprim[U1], ptrgeom[U1]);
                inflow_check_3vel(1,MAC(prim,i,j,k),NULL,ptrgeom[U1], 0) ;
                // projection may not preserve u^t to be real and rho>rhoscal u>uuscal
#if(JONCHECKS)
                if(jonchecks){
                  //fixup1zone(0,MAC(prim,i,j,k),ptrgeom[U1],0);
                  failreturn=check_pr(MAC(prim,i,j,k),MAC(prim,i,j,k),ptrgeom[U1],-3);
                  if(failreturn){
                    dualfprintf(fail_file,"Bad boundary zone, couldn't fix: i=%d j=%d k=%d\n",startpos[1]+i,startpos[2]+j,startpos[3]+k);
                    if (fail(i,j,k,FAIL_BCFIX) >= 1) return (1);
                  }
                }
#endif
#elif(WHICHVEL==VELREL4)
                get_geometry(i,j,k,dirprim[U1],ptrgeom[U1]) ;
                inflow_check_rel4vel(1,MAC(prim,i,j,k),NULL,ptrgeom[U1],0) ;
                if(limit_gamma(0,GAMMAMAX,GAMMAMAXRAD,MAC(prim,i,j,k),NULL,ptrgeom[U1],0)>=1)
                  FAILSTATEMENT("bounds.c:bound_prim()", "limit_gamma()", 1);
#endif 
              }
            } // end if not allowing inflow
          }


        }// end 2 3

      }// end if mycpupos[1]==0



    }
    else{
      dualfprintf(fail_file,"Shouldn't be here in bounds: horizonextrap version: dir=%d\n",X1DN);
      myexit(3946838);
    }


  }// end parallel region


  return(0);
}












/// X1 outer OUTFLOW/FIXEDOUTFLOW
int bound_x1up_outflow(
                       int boundstage, int finalstep, SFTYPE boundtime, int whichdir, int boundvartype, int *dirprim, int ispstag, FTYPE (*prim)[NSTORE2][NSTORE3][NPR],
                       int *inboundloop,
                       int *outboundloop,
                       int *innormalloop,
                       int *outnormalloop,
                       int (*inoutlohi)[NUMUPDOWN][NDIM],
                       int riin, int riout, int rjin, int rjout, int rkin, int rkout,
                       int *dosetbc,
                       int enerregion,
                       int *localenerpos
                       )
{




#pragma omp parallel  // assume don't require EOS
  {

    int i,j,k,pl,pliter;
    FTYPE vcon[NDIM]; // coordinate basis vcon
#if(WHICHVEL==VEL3)
    int failreturn;
#endif
    int ri, rj, rk; // reference i,j,k
    FTYPE prescale[NPR];
    int jj,kk;
    struct of_geom geomdontuse[NPR];
    struct of_geom *ptrgeom[NPR];
    struct of_geom rgeomdontuse[NPR];
    struct of_geom *ptrrgeom[NPR];

    // assign memory
    PALLLOOP(pl){
      ptrgeom[pl]=&(geomdontuse[pl]);
      ptrrgeom[pl]=&(rgeomdontuse[pl]);
    }


  
    if(((BCtype[X1UP]==OUTFLOW || BCtype[X1UP]==HORIZONOUTFLOW))||(BCtype[X1UP]==FIXEDOUTFLOW)||(BCtype[X1UP]==FREEOUTFLOW)){

      // outer r BC:
      if ( (totalsize[1]>1) && (mycpupos[1] == ncpux1 - 1) ) {


        OPENMPBCLOOPVARSDEFINELOOPX1DIR; OPENMPBCLOOPSETUPLOOPX1DIR;
        //////// LOOPX1dir{
#pragma omp for schedule(OPENMPSCHEDULE(),OPENMPCHUNKSIZE(blocksize))
        OPENMPBCLOOPBLOCK{
          OPENMPBCLOOPBLOCK2IJKLOOPX1DIR(j,k);


          ri=riout;
          rj=j;
          rk=k;


#if(OUTEREXTRAP==0)
          PALLLOOP(pl) get_geometry(ri, rj, rk, dirprim[pl], ptrrgeom[pl]);

          LOOPBOUND1OUT PBOUNDLOOP(pliter,pl) MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj,rk,pl);
#elif(OUTEREXTRAP==1)
          PALLLOOP(pl) get_geometry(ri, rj, rk, dirprim[pl], ptrrgeom[pl]);

          LOOPBOUND1OUT{
            PALLLOOP(pl) get_geometry(i, j, k, dirprim[pl], ptrgeom[pl]);

            PBOUNDLOOP(pliter,pl){
              if(pl>=RHO && pl<=UU){
                MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj,rk,pl) * (ptrrgeom[pl]->gdet/ptrgeom[pl]) ;
              }
            }
            PBOUNDLOOP(pliter,pl){
              if(pl==U1){ // treat U1 as special
                MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj,rk,pl) * (1. - 2*(i-ri)*dx[1]) ;
                for(pl=U2;pl<=U3;pl++){
                  MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj,rk,pl) * (1. - (i-ri)*dx[1]) ;
                }
              }
            }
            PBOUNDLOOP(pliter,pl){
              if(pl==B1){ // treat B1 special
                MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj,rk,pl) * (ptrrgeom[pl]->gdet/ptrgeom[pl]) ;
                for(pl=B2;pl<=B3;pl++){
                  MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj,rk,pl) * (1. - (i-ri)*dx[1]) ;
                }
              }
            }
            PBOUNDLOOP(pliter,pl){
              if(pl>=B3+1 && pl<NPRBOUND){
                MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj,rk,pl) * (ptrrgeom[pl]->gdet/ptrgeom[pl]) ;
              }
            }
          }
#elif(OUTEREXTRAP==2)
          get_geometry(ri, rj, rk, dirprim[0], ptrrgeom[0]);
          rescale(DORESCALE,1,MAC(prim,ri,rj,rk),ptrrgeom[0],prescale);
          LOOPBOUND1OUT{
            // set guess
            PBOUNDLOOP(pliter,pl) MACP0A1(prim,i,j,k,pl)=MACP0A1(prim,ri,rj,rk,pl);
            get_geometry(i, j, k, dirprim[0], ptrgeom[0]);
            rescale(UNRESCALE,1,MAC(prim,i,j,k),ptrgeom[0],prescale);
          }
#elif(OUTEREXTRAP==3)
          extrapfunc(X1UP,j,k,boundstage,finalstep,boundtime,whichdir,boundvartype,dirprim,ispstag,prim,inboundloop,outboundloop,innormalloop,outnormalloop,inoutlohi,riin,riout,rjin,rjout,rkin,rkout,dosetbc,enerregion,localenerpos);
#endif





          if(ispstag==0){

            if(((BCtype[X1UP]==OUTFLOW || BCtype[X1UP]==HORIZONOUTFLOW))||(BCtype[X1UP]==FIXEDOUTFLOW)){

              LOOPBOUND1OUT{
#if(WHICHVEL==VEL4)
                get_geometry(i, j, k, dirprim[U1], ptrgeom[U1]);
                inflow_check_4vel(1,MAC(prim,i,j,k),NULL,ptrgeom[U1],0) ;
#elif(WHICHVEL==VEL3)
                get_geometry(i, j, k, dirprim[U1], ptrgeom[U1]);
                inflow_check_3vel(1,MAC(prim,i,j,k),NULL,ptrgeom[U1],0) ;
                // projection may not preserve u^t to be real and rho>rhoscal u>uuscal
#if(JONCHECKS)
                if(jonchecks){
                  //fixup1zone(0,MAC(prim,i,j,k),ptrgeom[U1],0);
                  failreturn=check_pr(MAC(prim,i,j,k),MAC(prim,i,j,k),ptrgeom[U1],-3);
                  if(failreturn){
                    dualfprintf(fail_file,"Bad boundary zone, couldn't fix: i=%d j=%d k=%d\n",startpos[1]+i,startpos[2]+j,startpos[3]+k);
                    if (fail(i,j,k,FAIL_BCFIX) >= 1) return (1);
                  }
                }
#endif
#elif(WHICHVEL==VELREL4)
                get_geometry(i,j,k,dirprim[U1],ptrgeom[U1]) ;
                inflow_check_rel4vel(1,MAC(prim,i,j,k),NULL,ptrgeom[U1],0) ;
                if(limit_gamma(0,GAMMAMAX,GAMMAMAXRAD,MAC(prim,i,j,k),NULL,ptrgeom[U1], 0)>=1)
                  FAILSTATEMENT("bounds.c:bound_prim()", "limit_gamma()", 2);
#endif 
              }// end over i
            }// end if not allowing inflow

          }



        }// end 2 3
      }// end if mycpu is correct

    }
    else{
      dualfprintf(fail_file,"Shouldn't be here in bounds\n");
      myexit(3946839);
    }

  }// end parallel region


  return(0);
}






/// X1 inner R0SING
int bound_x1dn_sym(
                   int boundstage, int finalstep, SFTYPE boundtime, int whichdir, int boundvartype, int *dirprim, int ispstag, FTYPE (*prim)[NSTORE2][NSTORE3][NPR],
                   int *inboundloop,
                   int *outboundloop,
                   int *innormalloop,
                   int *outnormalloop,
                   int (*inoutlohi)[NUMUPDOWN][NDIM],
                   int riin, int riout, int rjin, int rjout, int rkin, int rkout,
                   int *dosetbc,
                   int enerregion,
                   int *localenerpos
                   )
{


#pragma omp parallel  // assume don't require EOS
  {
    int i,j,k,pl,pliter;
    FTYPE vcon[NDIM]; // coordinate basis vcon
#if(WHICHVEL==VEL3)
    int failreturn;
#endif
    int ri, rj, rk; // reference i,j,k
    FTYPE prescale[NPR];
    int jj,kk;


  
    if((BCtype[X1DN]==R0SING)||(BCtype[X1DN]==SYMM)||(BCtype[X1DN]==ASYMM) ){



      /* inner radial BC (preserves u^t rho and u) */
      if ( (totalsize[1]>1) && (mycpupos[1] == 0) ) {
        //////// LOOPX1dir{

        { // start block
          OPENMPBCLOOPVARSDEFINELOOPX1DIR; OPENMPBCLOOPSETUPLOOPX1DIR;
          //////// LOOPX1dir{
#pragma omp for schedule(OPENMPSCHEDULE(),OPENMPCHUNKSIZE(blocksize))
          OPENMPBCLOOPBLOCK{
            OPENMPBCLOOPBLOCK2IJKLOOPX1DIR(j,k);

            rj=j;
            rk=k;
            LOOPBOUND1IN{
              PBOUNDLOOP(pliter,pl){
                // SECTIONMARK: assume r=0 singularity can't move
                if(dirprim[pl]==FACE1 || dirprim[pl]==CORN3 || dirprim[pl]==CORN2 || dirprim[pl]==CORNT ) ri = -i; // FACE1 values
                else ri=-i-1; // "CENT" values for purposes of this BC
                MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj,rk,pl);
              }// over pl
            }// over boundary zones
          }
        }// end block



        if((BCtype[X1DN]==R0SING)||(BCtype[X1DN]==ASYMM) ){

          /* make sure b and u are antisymmetric at the poles   (preserves u^t rho and u) */
          //// LOOPX1dir{

          OPENMPBCLOOPVARSDEFINELOOPX1DIR; OPENMPBCLOOPSETUPLOOPX1DIR;
          //////// LOOPX1dir{
#pragma omp for schedule(OPENMPSCHEDULE(),OPENMPCHUNKSIZE(blocksize))
          OPENMPBCLOOPBLOCK{
            OPENMPBCLOOPBLOCK2IJKLOOPX1DIR(j,k);


            // SECTIONMARK: assume r=0 singularity can't move
            i=0;
            PBOUNDLOOP(pliter,pl){
              if(pl==U1 || pl==URAD1 || pl==B1){
                if(dirprim[pl]==FACE1 || dirprim[pl]==CORN3 || dirprim[pl]==CORN2 || dirprim[pl]==CORNT ){
                  MACP0A1(prim,i,j,k,pl) = 0.0;
                }
              }// else don't do this pl
            } // end over pl
 
            LOOPBOUND1IN {
              PBOUNDLOOP(pliter,pl){
                if(pl==U1 || pl==URAD1 || pl==B1){
                  MACP0A1(prim,i,j,k,pl) *= -1.;
                }// end if right pl
              } // end over pl
            } // end over boundary zones
          }// end loop 23
        }
      } //end if inner CPU wall
    }
    else{
      dualfprintf(fail_file,"Shouldn't be here in bounds\n");
      myexit(3946840);
    }

  } // end parallel region

  if(BCtype[X1DN]==R0SING){
    bound_x1dn_r0singfixinterior(boundstage,finalstep, boundtime, whichdir, boundvartype, dirprim,ispstag, prim,inboundloop,outboundloop,innormalloop,outnormalloop,inoutlohi,riin,riout,rjin,rjout,rkin,rkout,dosetbc,enerregion,localenerpos);
  }



  return(0);

}




/// X2 inner OUTFLOW/FIXEDOUTFLOW
int bound_x2dn_outflow_simple(
                              int boundstage, int finalstep, SFTYPE boundtime, int whichdir, int boundvartype, int *dirprim, int ispstag, FTYPE (*prim)[NSTORE2][NSTORE3][NPR],
                              int *inboundloop,
                              int *outboundloop,
                              int *innormalloop,
                              int *outnormalloop,
                              int (*inoutlohi)[NUMUPDOWN][NDIM],
                              int riin, int riout, int rjin, int rjout, int rkin, int rkout,
                              int *dosetbc,
                              int enerregion,
                              int *localenerpos
                              )
{



#pragma omp parallel  // assume don't require EOS
  {
    int i,j,k,pl,pliter;
    int localj1,globalj1;
    int localj2,globalj2;
    int rj1,rj2;
    struct of_geom geom[NPR],rgeom[NPR];
    FTYPE vcon[NDIM]; // coordinate basis vcon
#if(WHICHVEL==VEL3)
    int failreturn;
#endif
    int ri, rj, rk; // reference i,j,k
    FTYPE prescale[NPR];
    int jj,kk;
    struct of_geom geomdontuse[NPR];
    struct of_geom *ptrgeom[NPR];
    struct of_geom rgeomdontuse[NPR];
    struct of_geom *ptrrgeom[NPR];


    // assign memory
    PALLLOOP(pl){
      ptrgeom[pl]=&(geomdontuse[pl]);
      ptrrgeom[pl]=&(rgeomdontuse[pl]);
    }


    if(((BCtype[X2DN]==OUTFLOW || BCtype[X2DN]==HORIZONOUTFLOW))||(BCtype[X2DN]==FIXEDOUTFLOW)||(BCtype[X1DN]==FREEOUTFLOW)){


      if ( (totalsize[2]>1) && (mycpupos[2] <= 0)) {
        /* inner r boundary condition: u, just copy */

        OPENMPBCLOOPVARSDEFINELOOPX2DIR; OPENMPBCLOOPSETUPLOOPX2DIR;
        //////// LOOPX2dir{
#pragma omp for schedule(OPENMPSCHEDULE(),OPENMPCHUNKSIZE(blocksize))
        OPENMPBCLOOPBLOCK{
          OPENMPBCLOOPBLOCK2IJKLOOPX2DIR(i,k);



          ri=i;
          rj=rjin;
          rk=k;


          PALLLOOP(pl) get_geometry(ri, rj, rk, dirprim[pl], ptrrgeom[pl]);

          LOOPBOUND2IN{ // bound entire region inside non-evolved portion of grid
            PBOUNDLOOP(pliter,pl){
              //       dualfprintf(fail_file,"pl=%d i=%d j=%d k=%d : ri=%d rj=%d rk=%d\n",pl,i,j,k,ri,rj,rk);
              MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj,rk,pl);
            }
          }




          if(ispstag==0){

            if((BCtype[X2DN]==OUTFLOW)||(BCtype[X2DN]==FIXEDOUTFLOW)){
              // GODMARK: assume all velocities at same location when doing inflow check
              LOOPBOUND2IN{
#if(WHICHVEL==VEL4)
                get_geometry(i, j, k, dirprim[U2], ptrgeom[U2]);
                inflow_check_4vel(2,MAC(prim,i,j,k),NULL,ptrgeom[U2], 0) ;
#elif(WHICHVEL==VEL3)
                get_geometry(i, j, k, dirprim[U2], ptrgeom[U2]);
                inflow_check_3vel(2,MAC(prim,i,j,k),NULL,ptrgeom[U2], 0) ;
                // projection may not preserve u^t to be real and rho>rhoscal u>uuscal
#if(JONCHECKS)
                if(jonchecks){
                  //fixup1zone(0,MAC(prim,i,j,k),ptrgeom[U2],0);
                  failreturn=check_pr(MAC(prim,i,j,k),MAC(prim,i,j,k),ptrgeom[U2],-3);
                  if(failreturn){
                    dualfprintf(fail_file,"Bad boundary zone, couldn't fix: i=%d j=%d k=%d\n",startpos[1]+i,startpos[2]+j,startpos[3]+k);
                    if (fail(i,j,k,FAIL_BCFIX) >= 1) return (1);
                  }
                }
#endif
#elif(WHICHVEL==VELREL4)
                get_geometry(i,j,k,dirprim[U2],ptrgeom[U2]) ;
                inflow_check_rel4vel(2,MAC(prim,i,j,k),NULL,ptrgeom[U2],0) ;
                if(limit_gamma(0,GAMMAMAX,GAMMAMAXRAD,MAC(prim,i,j,k),NULL,ptrgeom[U2],0)>=1)
                  FAILSTATEMENT("bounds.c:bound_prim()", "limit_gamma()", 1);
#endif 
              }
            } // end if not allowing inflow
          }


        }// end 2 3

      }// end if mycpupos[2]==0



    }
    else{
      dualfprintf(fail_file,"Shouldn't be here in bounds\n");
      myexit(39377841);
    }


  }// end parallel region


  return(0);
}

/// X2 outer OUTFLOW/FIXEDOUTFLOW
int bound_x2up_outflow_simple(
                              int boundstage, int finalstep, SFTYPE boundtime, int whichdir, int boundvartype, int *dirprim, int ispstag, FTYPE (*prim)[NSTORE2][NSTORE3][NPR],
                              int *inboundloop,
                              int *outboundloop,
                              int *innormalloop,
                              int *outnormalloop,
                              int (*inoutlohi)[NUMUPDOWN][NDIM],
                              int riin, int riout, int rjin, int rjout, int rkin, int rkout,
                              int *dosetbc,
                              int enerregion,
                              int *localenerpos
                              )
{




#pragma omp parallel  // assume don't require EOS
  {

    int i,j,k,pl,pliter;
    int localj1,globalj1;
    int localj2,globalj2;
    int rj1,rj2;
    FTYPE vcon[NDIM]; // coordinate basis vcon
#if(WHICHVEL==VEL3)
    int failreturn;
#endif
    int ri, rj, rk; // reference i,j,k
    FTYPE prescale[NPR];
    int jj,kk;
    struct of_geom geomdontuse[NPR];
    struct of_geom *ptrgeom[NPR];
    struct of_geom rgeomdontuse[NPR];
    struct of_geom *ptrrgeom[NPR];

    // assign memory
    PALLLOOP(pl){
      ptrgeom[pl]=&(geomdontuse[pl]);
      ptrrgeom[pl]=&(rgeomdontuse[pl]);
    }


  
    if((BCtype[X2UP]==OUTFLOW)||(BCtype[X2UP]==FIXEDOUTFLOW)||(BCtype[X2UP]==FREEOUTFLOW)){

      // outer r BC:
      if ( (totalsize[2]>1) && (mycpupos[2] == ncpux2 - 1) ) {


        OPENMPBCLOOPVARSDEFINELOOPX2DIR; OPENMPBCLOOPSETUPLOOPX2DIR;
        //////// LOOPX2dir{
#pragma omp for schedule(OPENMPSCHEDULE(),OPENMPCHUNKSIZE(blocksize))
        OPENMPBCLOOPBLOCK{
          OPENMPBCLOOPBLOCK2IJKLOOPX2DIR(i,k);


          ri=i;
          rj=rjout;
          rk=k;

          PALLLOOP(pl) get_geometry(ri, rj, rk, dirprim[pl], ptrrgeom[pl]);

          LOOPBOUND2OUT PBOUNDLOOP(pliter,pl) MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj,rk,pl);





          if(ispstag==0){

            if((BCtype[X2UP]==OUTFLOW)||(BCtype[X2UP]==FIXEDOUTFLOW)){

              LOOPBOUND2OUT{
#if(WHICHVEL==VEL4)
                get_geometry(i, j, k, dirprim[U2], ptrgeom[U2]);
                inflow_check_4vel(2,MAC(prim,i,j,k),NULL,ptrgeom[U2],0) ;
#elif(WHICHVEL==VEL3)
                get_geometry(i, j, k, dirprim[U2], ptrgeom[U2]);
                inflow_check_3vel(2,MAC(prim,i,j,k),NULL,ptrgeom[U2],0) ;
                // projection may not preserve u^t to be real and rho>rhoscal u>uuscal
#if(JONCHECKS)
                if(jonchecks){
                  //fixup1zone(0,MAC(prim,i,j,k),ptrgeom[U2],0);
                  failreturn=check_pr(MAC(prim,i,j,k),MAC(prim,i,j,k),ptrgeom[U2],-3);
                  if(failreturn){
                    dualfprintf(fail_file,"Bad boundary zone, couldn't fix: i=%d j=%d k=%d\n",startpos[1]+i,startpos[2]+j,startpos[3]+k);
                    if (fail(i,j,k,FAIL_BCFIX) >= 1) return (1);
                  }
                }
#endif
#elif(WHICHVEL==VELREL4)
                get_geometry(i,j,k,dirprim[U2],ptrgeom[U2]) ;
                inflow_check_rel4vel(2,MAC(prim,i,j,k),NULL,ptrgeom[U2],0) ;
                if(limit_gamma(0,GAMMAMAX,GAMMAMAXRAD,MAC(prim,i,j,k),NULL,ptrgeom[U2], 0)>=1)
                  FAILSTATEMENT("bounds.c:bound_prim()", "limit_gamma()", 2);
#endif 
              }// end over i
            }// end if not allowing inflow

          }



        }// end 2 3
      }// end if mycpu is correct

    }
    else{
      dualfprintf(fail_file,"Shouldn't be here in bounds\n");
      myexit(39324842);
    }

  }// end parallel region


  return(0);
}
















/// X2 inner POLARAXIS
/// with full3d, flip sign of both B2 and B3
/// Flip B2 because ghost cells will then be same sign if pointing in same physical location, and opposite sign if pointing opposite physical location across the pole.
/// Flip B3 because RBhat3\propto \theta (as growing enclosed current from pole) gives Bhat3\propto constant near pole and so Bhat3\propto \theta B3 and so B3\propto \constant 1/\theta.
/// So can either interpolation (e.g.) \detg B3 and \detg v3 and obtain higher-order accuracy near pole.  Or can flip sign of B3 and v3 and keep more stable but still no diffusive term that otherwise B3 and v3 would have due to their sign change across the pole.
int bound_x2dn_polaraxis_full3d(
                                int whichcall,
                                int boundstage, int finalstep, SFTYPE boundtime, int whichdir, int boundvartype, int *dirprim, int ispstag, FTYPE (*prim)[NSTORE2][NSTORE3][NPR],
                                int *inboundloop,
                                int *outboundloop,
                                int *innormalloop,
                                int *outnormalloop,
                                int (*inoutlohi)[NUMUPDOWN][NDIM],
                                int riin, int riout, int rjin, int rjout, int rkin, int rkout,
                                int *dosetbc,
                                int enerregion,
                                int *localenerpos
                                )
{



#pragma omp parallel  // assume don't require EOS
  {
    int i,j,k,pl,pliter;
    FTYPE vcon[NDIM]; // coordinate basis vcon
#if(WHICHVEL==VEL3)
    int failreturn;
#endif
    int ri, rj, rk; // reference i,j,k
    FTYPE prescale[NPR];
    int jj,kk;



    if(BCtype[X2DN]==POLARAXIS && special3dspc){
      
      /* inner polar BC (preserves u^t rho and u) */
      if ( (totalsize[2]>1) && (mycpupos[2] == 0) ) {

        if(whichcall==1 && ncpux3==1){
          // if ncpux3>1 then this is handled by MPI
          ////////   LOOPX2dir{

          OPENMPBCLOOPVARSDEFINELOOPX2DIR; OPENMPBCLOOPSETUPLOOPX2DIR;
#pragma omp for schedule(OPENMPSCHEDULE(),OPENMPCHUNKSIZE(blocksize))
          OPENMPBCLOOPBLOCK{
            OPENMPBCLOOPBLOCK2IJKLOOPX2DIR(i,k);

            ri=i;
            rk=(k+(int)N3/2)%N3;
            LOOPBOUND2IN{
              PBOUNDLOOP(pliter,pl){
                // assume polar axis can't move SECTIONMARK
                if(dirprim[pl]==FACE2 || dirprim[pl]==CORN3 || dirprim[pl]==CORN1 || dirprim[pl]==CORNT ) rj = -j; // FACE2 values
                else rj=-j-1; // "CENT" values for purposes of this BC
                MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj,rk,pl);

                // flip sign
                if(pl==U1) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPU1;
                if(pl==B1) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPB1;
                if(pl==URAD1) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPU1;
                if(pl==U2) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPU2;
                if(pl==B2) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPB2;
                if(pl==URAD2) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPU2;
                if(pl==U3) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPU3;
                if(pl==B3) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPB3;
                if(pl==URAD3) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPU3;

#if(DEBUGINOUTLOOPS)  
                dualfprintf(fail_file,"INNER pole1: ispstag=%d  pl=%d :: ri=%d rj=%d rk=%d i=%d j=%d k=%d\n",ispstag,pl,ri,rj,rk,i,j,k);
                if(!isfinite(MACP0A1(prim,ri,rj,rk,pl))){
                  dualfprintf(fail_file,"INNER pole1: caught copying nan ri=%d rj=%d rk=%d pl=%d\n",ri,rj,rk,pl);
                }
#endif


              }// end over pl
            }// end over j

            // also do j=0 (this just makes B2 @ FACE2-type location at j=0 at k and rk the same in correct sense)
            j=0;
            PBOUNDLOOP(pliter,pl){
              if(dirprim[pl]==FACE2 || dirprim[pl]==CORN3 || dirprim[pl]==CORN1 || dirprim[pl]==CORNT ){
                // only do j=0 if at pole exactly
                rj = -j; // FACE2 values
                MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj,rk,pl);
   
                if(pl==U1) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPU1;
                if(pl==B1) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPB1;
                if(pl==URAD1) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPU1;
                // flip sign
                if(pl==U2) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPU2;
                if(pl==B2) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPB2;
                if(pl==URAD2) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPU2;
                // NOTEMARK: No U3,B3 staggered yet, so below not used
                if(pl==U3) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPU3;
                if(pl==B3) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPB3;
                if(pl==URAD3) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPU3;

#if(DEBUGINOUTLOOPS)  
                dualfprintf(fail_file,"INNER pole2: ispstag=%d  pl=%d :: ri=%d rj=%d rk=%d i=%d j=%d k=%d\n",ispstag,pl,ri,rj,rk,i,j,k);
                if(!isfinite(MACP0A1(prim,ri,rj,rk,pl))){
                  dualfprintf(fail_file,"INNER pole2: caught copying nan ri=%d rj=%d rk=%d pl=%d\n",ri,rj,rk,pl);
                }
#endif


              }
            }

          }// end over i,k
        }// end if ncpux3==1

        // SUPERGODMARK: continue to use for now
        // only do poledeath() after MPI call (i.e. whichcall==2)
        if(BCtype[X2DN]==POLARAXIS && (whichcall==2 && ncpux3>1 || whichcall==1 && ncpux3==1) ){
          if(POLEDEATH || POLEGAMMADEATH)   poledeath(X2DN,boundstage,finalstep,boundtime,whichdir,boundvartype,dirprim,ispstag,prim,inboundloop,outboundloop,innormalloop,outnormalloop,inoutlohi,riin,riout,rjin,rjout,rkin,rkout,dosetbc,enerregion,localenerpos);
          if(POLESMOOTH) polesmooth(X2DN,boundstage,finalstep,boundtime,whichdir,boundvartype,dirprim,ispstag,prim,inboundloop,outboundloop,innormalloop,outnormalloop,inoutlohi,riin,riout,rjin,rjout,rkin,rkout,dosetbc,enerregion,localenerpos);
        }


      }//end if inner CPU wall





    }
    else{
      dualfprintf(fail_file,"Shouldn't be here in bounds\n");
      myexit(3946843);
    }



  } // end parallel region




  //end if special transmissive BCs at poles
  return(0);
}





/// X2 inner POLARAXIS
int bound_x2dn_polaraxis(
                         int boundstage, int finalstep, SFTYPE boundtime, int whichdir, int boundvartype, int *dirprim, int ispstag, FTYPE (*prim)[NSTORE2][NSTORE3][NPR],
                         int *inboundloop,
                         int *outboundloop,
                         int *innormalloop,
                         int *outnormalloop,
                         int (*inoutlohi)[NUMUPDOWN][NDIM],
                         int riin, int riout, int rjin, int rjout, int rkin, int rkout,
                         int *dosetbc,
                         int enerregion,
                         int *localenerpos
                         )
{



#pragma omp parallel  // assume don't require EOS
  {
    int i,j,k,pl,pliter;
    FTYPE vcon[NDIM]; // coordinate basis vcon
#if(WHICHVEL==VEL3)
    int failreturn;
#endif
    int ri, rj, rk; // reference i,j,k
    FTYPE prescale[NPR];
    int jj,kk;


    if((BCtype[X2DN]==POLARAXIS)||(BCtype[X2DN]==SYMM)||(BCtype[X2DN]==ASYMM) ){


      if (  (totalsize[2]>1) && (mycpupos[2] == 0) ){

        /////      LOOPX2dir{

        {// block region
          OPENMPBCLOOPVARSDEFINELOOPX2DIR; OPENMPBCLOOPSETUPLOOPX2DIR;
#pragma omp for schedule(OPENMPSCHEDULE(),OPENMPCHUNKSIZE(blocksize))
          OPENMPBCLOOPBLOCK{
            OPENMPBCLOOPBLOCK2IJKLOOPX2DIR(i,k);
 
            ri=i;
            rk=k;
            LOOPBOUND2IN{
              PBOUNDLOOP(pliter,pl){
                // assume polar axis can't move SECTIONMARK
                if(dirprim[pl]==FACE2 || dirprim[pl]==CORN3 || dirprim[pl]==CORN1 || dirprim[pl]==CORNT ) rj = -j; // FACE2 values
                else rj=-j-1; // "CENT" values for purposes of this BC
                MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj,rk,pl);
              }
            }
          }
        }// end blocked region


        if((BCtype[X2DN]==POLARAXIS)||(BCtype[X2DN]==ASYMM) ){

          /* make sure b and u are antisymmetric at the poles   (preserves u^t rho and u) */
          //// LOOPX2dir{

          OPENMPBCLOOPVARSDEFINELOOPX2DIR; OPENMPBCLOOPSETUPLOOPX2DIR;
#pragma omp for schedule(OPENMPSCHEDULE(),OPENMPCHUNKSIZE(blocksize))
          OPENMPBCLOOPBLOCK{
            OPENMPBCLOOPBLOCK2IJKLOOPX2DIR(i,k);


            // assume polar axis can't move SECTIONMARK
            j=0;
            PBOUNDLOOP(pliter,pl){
              if(pl==U2 || pl==URAD2 || pl==B2){
                if(dirprim[pl]==FACE2 || dirprim[pl]==CORN3 || dirprim[pl]==CORN1 || dirprim[pl]==CORNT ){
                  MACP0A1(prim,i,j,k,pl) = 0.0;
                }
              }// else don't do this pl
            } // end over pl
 
 
            if(BCtype[X2DN]==POLARAXIS){
              LOOPBOUND2IN {
                PBOUNDLOOP(pliter,pl){
                  if(pl==U1) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPU1;
                  if(pl==B1) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPB1;
                  if(pl==URAD1) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPU1;
                  if(pl==U2) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPU2;
                  if(pl==B2) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPB2;
                  if(pl==URAD2) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPU2;
                  if(pl==U3) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPU3;
                  if(pl==B3) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPB3;
                  if(pl==URAD3) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPU3;
                } // end over pl
              } // end over boundary cells
            }// end of polar axis type
            else if(BCtype[X2DN]==ASYMM){
              LOOPBOUND2IN {
                PBOUNDLOOP(pliter,pl){
                  if(pl==U2 || pl==URAD2 || pl==B2) MACP0A1(prim,i,j,k,pl) *= -1.0;
                } // end over pl
              } // end over boundary cells
            }// end of polar axis type
          }// end loop 13


        }// end if polar or asym condition

        if(BCtype[X2DN]==POLARAXIS){
          if(POLEDEATH || POLEGAMMADEATH)   poledeath(X2DN,boundstage,finalstep,boundtime,whichdir,boundvartype,dirprim,ispstag,prim,inboundloop,outboundloop,innormalloop,outnormalloop,inoutlohi,riin,riout,rjin,rjout,rkin,rkout,dosetbc,enerregion,localenerpos);
          if(POLESMOOTH) polesmooth(X2DN,boundstage,finalstep,boundtime,whichdir,boundvartype,dirprim,ispstag,prim,inboundloop,outboundloop,innormalloop,outnormalloop,inoutlohi,riin,riout,rjin,rjout,rkin,rkout,dosetbc,enerregion,localenerpos);
        }
 
      }// end if inner CPU wall



    }// end if polar asym or asym
    else{
      dualfprintf(fail_file,"Shouldn't be here in bounds\n");
      myexit(3946844);
    }

  }// end parallel region

    

  return(0);
}





/// X2 outer POLARAXIS full3d
int bound_x2up_polaraxis_full3d(
                                int whichcall,
                                int boundstage, int finalstep, SFTYPE boundtime, int whichdir, int boundvartype, int *dirprim, int ispstag, FTYPE (*prim)[NSTORE2][NSTORE3][NPR],
                                int *inboundloop,
                                int *outboundloop,
                                int *innormalloop,
                                int *outnormalloop,
                                int (*inoutlohi)[NUMUPDOWN][NDIM],
                                int riin, int riout, int rjin, int rjout, int rkin, int rkout,
                                int *dosetbc,
                                int enerregion,
                                int *localenerpos
                                )
{





#pragma omp parallel  // assume don't require EOSs
  {
    int i,j,k,pl,pliter;
    FTYPE vcon[NDIM]; // coordinate basis vcon
#if(WHICHVEL==VEL3)
    int failreturn;
#endif
    int ri, rj, rk; // reference i,j,k
    FTYPE prescale[NPR];
    int jj,kk;



    if(BCtype[X2UP]==POLARAXIS && special3dspc){
 

      if (  (totalsize[2]>1) && (mycpupos[2] == ncpux2-1) ) {


        if(whichcall==1 && ncpux3==1){
          // if ncpux3>1 then this is handled by MPI

          //////   LOOPX2dir{
          OPENMPBCLOOPVARSDEFINELOOPX2DIR; OPENMPBCLOOPSETUPLOOPX2DIR;
#pragma omp for schedule(OPENMPSCHEDULE(),OPENMPCHUNKSIZE(blocksize))
          OPENMPBCLOOPBLOCK{
            OPENMPBCLOOPBLOCK2IJKLOOPX2DIR(i,k);


            ri=i;
            rk=(k+(int)N3/2)%N3;
            LOOPBOUND2OUT{
              PBOUNDLOOP(pliter,pl){
                // assume polar axis can't move SECTIONMARK
                if(dirprim[pl]==FACE2 || dirprim[pl]==CORN3 || dirprim[pl]==CORN1 || dirprim[pl]==CORNT ) rj = 2*N2-j; // FACE2 values
                else rj=2*(N2-1)-j+1; // "CENT" values for purposes of this BC
                MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj,rk,pl);

                // flip sign
                if(pl==U1) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPU1;
                if(pl==B1) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPB1;
                if(pl==URAD1) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPU1;
                if(pl==U2) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPU2;
                if(pl==B2) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPB2;
                if(pl==URAD2) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPU2;
                if(pl==U3) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPU3;
                if(pl==B3) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPB3;
                if(pl==URAD3) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPU3;

#if(DEBUGINOUTLOOPS)  
                dualfprintf(fail_file,"OUTER pole1: ispstag=%d  pl=%d :: ri=%d rj=%d rk=%d i=%d j=%d k=%d\n",ispstag,pl,ri,rj,rk,i,j,k);
                if(!isfinite(MACP0A1(prim,ri,rj,rk,pl))){
                  dualfprintf(fail_file,"OUTER pole1: caught copying nan ri=%d rj=%d rk=%d pl=%d\n",ri,rj,rk,pl);
                }
#endif


              }// end over pl
            }// end over j

            // also do j=N2 (this just makes B2 @ FACE2-type location at j=N2 at k and rk the same in correct sense)
            j=N2;
            PBOUNDLOOP(pliter,pl){
              if(dirprim[pl]==FACE2 || dirprim[pl]==CORN3 || dirprim[pl]==CORN1 || dirprim[pl]==CORNT ){
                // only do j=0 if at pole exactly
                rj = 2*N2-j; // FACE2 values
                MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj,rk,pl);
   
                // flip sign
                if(pl==U1) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPU1;
                if(pl==B1) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPB1;
                if(pl==URAD1) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPU1;
                if(pl==U2) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPU2;
                if(pl==B2) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPB2;
                if(pl==URAD2) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPU2;
                if(pl==U3) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPU3;
                if(pl==B3) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPB3;
                if(pl==URAD3) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPU3;

#if(DEBUGINOUTLOOPS)  
                dualfprintf(fail_file,"OUTER pole2: ispstag=%d  pl=%d :: ri=%d rj=%d rk=%d i=%d j=%d k=%d\n",ispstag,pl,ri,rj,rk,i,j,k);
                if(!isfinite(MACP0A1(prim,ri,rj,rk,pl))){
                  dualfprintf(fail_file,"OUTER pole2: caught copying nan ri=%d rj=%d rk=%d pl=%d\n",ri,rj,rk,pl);
                }
#endif

              }
            }

          }// end over i,k
        }// end if ncpux3==1

        // SUPERGODMARK: continue to use for now
        // only do poledeath() after MPI call (i.e. whichcall==2)
        if(BCtype[X2UP]==POLARAXIS && (whichcall==2 && ncpux3>1 || whichcall==1 && ncpux3==1) ){
          if(POLEDEATH || POLEGAMMADEATH)   poledeath(X2UP,boundstage,finalstep,boundtime,whichdir,boundvartype,dirprim,ispstag,prim,inboundloop,outboundloop,innormalloop,outnormalloop,inoutlohi,riin,riout,rjin,rjout,rkin,rkout,dosetbc,enerregion,localenerpos);
          if(POLESMOOTH) polesmooth(X2UP,boundstage,finalstep,boundtime,whichdir,boundvartype,dirprim,ispstag,prim,inboundloop,outboundloop,innormalloop,outnormalloop,inoutlohi,riin,riout,rjin,rjout,rkin,rkout,dosetbc,enerregion,localenerpos);
        }

      }// end if outer CPU wall

    }
    else{
      dualfprintf(fail_file,"Shouldn't be here in bounds\n");
      myexit(3946845);
    }

  }// end parallel region
    

  return(0);
}





/// X2 outer POLARAXIS
int bound_x2up_polaraxis(
                         int boundstage, int finalstep, SFTYPE boundtime, int whichdir, int boundvartype, int *dirprim, int ispstag, FTYPE (*prim)[NSTORE2][NSTORE3][NPR],
                         int *inboundloop,
                         int *outboundloop,
                         int *innormalloop,
                         int *outnormalloop,
                         int (*inoutlohi)[NUMUPDOWN][NDIM],
                         int riin, int riout, int rjin, int rjout, int rkin, int rkout,
                         int *dosetbc,
                         int enerregion,
                         int *localenerpos
                         )
{





#pragma omp parallel  // assume don't require EOS
  {
    int i,j,k,pl,pliter;
    FTYPE vcon[NDIM]; // coordinate basis vcon
#if(WHICHVEL==VEL3)
    int failreturn;
#endif
    int ri, rj, rk; // reference i,j,k
    FTYPE prescale[NPR];
    int jj,kk;




  
    if((BCtype[X2UP]==POLARAXIS)||(BCtype[X2UP]==SYMM)||(BCtype[X2UP]==ASYMM) ){


      if (  (totalsize[2]>1) && (mycpupos[2] == ncpux2-1) ) {

        //////      LOOPX2dir{
        {// block region
          OPENMPBCLOOPVARSDEFINELOOPX2DIR; OPENMPBCLOOPSETUPLOOPX2DIR;
#pragma omp for schedule(OPENMPSCHEDULE(),OPENMPCHUNKSIZE(blocksize))
          OPENMPBCLOOPBLOCK{
            OPENMPBCLOOPBLOCK2IJKLOOPX2DIR(i,k);


            ri=i;
            rk=k;
            LOOPBOUND2OUT{
              PBOUNDLOOP(pliter,pl){
                // assume polar axis can't move SECTIONMARK
                if(dirprim[pl]==FACE2 || dirprim[pl]==CORN3 || dirprim[pl]==CORN1 || dirprim[pl]==CORNT ) rj = 2*N2-j; // FACE2 values
                else rj=2*(N2-1)-j+1; // "CENT" values for purposes of this BC
                MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj,rk,pl);
              }
            }
          }
        }
    
        if((BCtype[X2UP]==POLARAXIS)||(BCtype[X2UP]==ASYMM) ){

          /* make sure b and u are antisymmetric at the poles   (preserves u^t rho and u) */
          ////// LOOPX2dir{
          OPENMPBCLOOPVARSDEFINELOOPX2DIR; OPENMPBCLOOPSETUPLOOPX2DIR;
#pragma omp for schedule(OPENMPSCHEDULE(),OPENMPCHUNKSIZE(blocksize))
          OPENMPBCLOOPBLOCK{
            OPENMPBCLOOPBLOCK2IJKLOOPX2DIR(i,k);


            j=N2;
            PBOUNDLOOP(pliter,pl){
              if(pl==U2 || pl==URAD2 || pl==B2){
                if(dirprim[pl]==FACE2 || dirprim[pl]==CORN3 || dirprim[pl]==CORN1 || dirprim[pl]==CORNT ){
                  MACP0A1(prim,i,j,k,pl) = 0.0;
                }
              }// else don't do this pl
            } // end over pl


            if(BCtype[X2UP]==POLARAXIS){
              LOOPBOUND2OUT {
                PBOUNDLOOP(pliter,pl){
                  if(pl==U1) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPU1;
                  if(pl==B1) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPB1;
                  if(pl==URAD1) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPU1;
                  if(pl==U2) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPU2;
                  if(pl==B2) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPB2;
                  if(pl==URAD2) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPU2;
                  if(pl==U3) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPU3;
                  if(pl==B3) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPB3;
                  if(pl==URAD3) MACP0A1(prim,i,j,k,pl) *= SIGNFLIPU3;
                } // end over pl
              } // end over bondary cells
            }// end if polar axis
            else if(BCtype[X2UP]==ASYMM){
              LOOPBOUND2OUT {
                PBOUNDLOOP(pliter,pl){
                  if(pl==U2 || pl==URAD2 || pl==B2) MACP0A1(prim,i,j,k,pl) *= -1.0;
                } // end over pl
              } // end over bondary cells
            }
          }// end loop 13

        }// end if reflecting type conditions


        if(BCtype[X2UP]==POLARAXIS){
          if(POLEDEATH || POLEGAMMADEATH)   poledeath(X2UP,boundstage,finalstep,boundtime,whichdir,boundvartype,dirprim,ispstag,prim,inboundloop,outboundloop,innormalloop,outnormalloop,inoutlohi,riin,riout,rjin,rjout,rkin,rkout,dosetbc,enerregion,localenerpos);
          if(POLESMOOTH) polesmooth(X2UP,boundstage,finalstep,boundtime,whichdir,boundvartype,dirprim,ispstag,prim,inboundloop,outboundloop,innormalloop,outnormalloop,inoutlohi,riin,riout,rjin,rjout,rkin,rkout,dosetbc,enerregion,localenerpos);
        }
      
      }// end if mycpupos[2]==ncpux2-1
      
  

    }
    else{
      dualfprintf(fail_file,"Shouldn't be here in bounds\n");
      myexit(3946846);
    }

  }// end parallel region


  return(0);
}




/// X1 periodic
int bound_x1_periodic(
                      int boundstage, int finalstep, SFTYPE boundtime, int whichdir, int boundvartype, int *dirprim, int ispstag, FTYPE (*prim)[NSTORE2][NSTORE3][NPR],
                      int *inboundloop,
                      int *outboundloop,
                      int *innormalloop,
                      int *outnormalloop,
                      int (*inoutlohi)[NUMUPDOWN][NDIM],
                      int riin, int riout, int rjin, int rjout, int rkin, int rkout,
                      int *dosetbc,
                      int enerregion,
                      int *localenerpos
                      )
{



#pragma omp parallel  // assume don't require EOS
  {
    int i,j,k,pl,pliter;
    FTYPE vcon[NDIM]; // coordinate basis vcon
#if(WHICHVEL==VEL3)
    int failreturn;
#endif
    int ri, rj, rk; // reference i,j,k
    FTYPE prescale[NPR];
    int jj,kk;


    if( (BCtype[X1DN]==PERIODIC)&&(BCtype[X1UP]==PERIODIC) ){


      // periodic x1
      if ( (totalsize[1]>1) && (mycpupos[1] == 0)&&(mycpupos[1] == ncpux1 - 1) ) {
        // just copy from one side to another

        //// LOOPX1dir{

        OPENMPBCLOOPVARSDEFINELOOPX1DIR; OPENMPBCLOOPSETUPLOOPX1DIR;
#pragma omp for schedule(OPENMPSCHEDULE(),OPENMPCHUNKSIZE(blocksize))
        OPENMPBCLOOPBLOCK{
          OPENMPBCLOOPBLOCK2IJKLOOPX1DIR(j,k);


          // copy from upper side to lower boundary zones
          ri=riout;
          rj=j;
          rk=k;
          LOOPBOUND1IN PBOUNDLOOP(pliter,pl){
            MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri+1+i,rj,rk,pl);

     
#if(DEBUGINOUTLOOPS)  
            dualfprintf(fail_file,"INNER X1: ispstag=%d  pl=%d :: ri=%d rj=%d rk=%d (otherri=%d) i=%d j=%d k=%d\n",ispstag,pl,ri,rj,rk,ri+SHIFT1+i,i,j,k);
            if(!isfinite(MACP0A1(prim,ri+SHIFT1+i,rj,rk,pl))){
              dualfprintf(fail_file,"INNER X1: caught copying nan ri=%d rj=%d rk=%d pl=%d\n",ri,rj,rk,pl);
            }
#endif

          }

          // copy from lower side to upper boundary zones
          ri=riin;
          rj=j;
          rk=k;
          LOOPBOUND1OUT PBOUNDLOOP(pliter,pl){
            MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri+(i-N1),rj,rk,pl);

#if(DEBUGINOUTLOOPS)  
            dualfprintf(fail_file,"OUTER X1: ispstag=%d pl=%d :: ri=%d rj=%d rk=%d (otherri=%d) i=%d j=%d k=%d\n",ispstag,pl,ri,rj,ri+(i-N1),rk,i,j,k);
            if(!isfinite(MACP0A1(prim,ri+(i-N1),rj,rk,pl))){
              dualfprintf(fail_file,"INNER X1: caught copying nan ri=%d rj=%d rk=%d pl=%d\n",ri,rj,rk,pl);
            }
#endif

          }
        }
      }


    }
    else{
      dualfprintf(fail_file,"Shouldn't be here in bounds\n");
      myexit(1946847);
    }


  }// end parallel region

  return(0);
}

/// X2 inner periodic
int bound_x2_periodic(
                      int boundstage, int finalstep, SFTYPE boundtime, int whichdir, int boundvartype, int *dirprim, int ispstag, FTYPE (*prim)[NSTORE2][NSTORE3][NPR],
                      int *inboundloop,
                      int *outboundloop,
                      int *innormalloop,
                      int *outnormalloop,
                      int (*inoutlohi)[NUMUPDOWN][NDIM],
                      int riin, int riout, int rjin, int rjout, int rkin, int rkout,
                      int *dosetbc,
                      int enerregion,
                      int *localenerpos
                      )
{



#pragma omp parallel  // assume don't require EOS
  {
    int i,j,k,pl,pliter;
    FTYPE vcon[NDIM]; // coordinate basis vcon
#if(WHICHVEL==VEL3)
    int failreturn;
#endif
    int ri, rj, rk; // reference i,j,k
    FTYPE prescale[NPR];
    int jj,kk;


    if( (BCtype[X2DN]==PERIODIC)&&(BCtype[X2UP]==PERIODIC) ){


      // periodic x2
      if ( (totalsize[2]>1) && (mycpupos[2] == 0)&&(mycpupos[2] == ncpux2 - 1) ) {
        // just copy from one side to another

        //// LOOPX2dir{

        OPENMPBCLOOPVARSDEFINELOOPX2DIR; OPENMPBCLOOPSETUPLOOPX2DIR;
#pragma omp for schedule(OPENMPSCHEDULE(),OPENMPCHUNKSIZE(blocksize))
        OPENMPBCLOOPBLOCK{
          OPENMPBCLOOPBLOCK2IJKLOOPX2DIR(i,k);


          // copy from upper side to lower boundary zones
          ri=i;
          rj=rjout;
          rk=k;
          LOOPBOUND2IN PBOUNDLOOP(pliter,pl){
            MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj+SHIFT2+j,rk,pl);

     
#if(DEBUGINOUTLOOPS)
            dualfprintf(fail_file,"INNER X2: ispstag=%d  pl=%d :: ri=%d rj=%d rk=%d (otherrj=%d) i=%d j=%d k=%d\n",ispstag,pl,ri,rj,rk,rj+SHIFT2+j,i,j,k);
            dualfprintf(fail_file,"ref: %g\n",MACP0A1(prim,ri,rj+SHIFT2+j,rk,pl));
            if(!isfinite(MACP0A1(prim,ri,rj+SHIFT2+j,rk,pl))){
              dualfprintf(fail_file,"INNER X2: caught copying nan ri=%d rj=%d rk=%d pl=%d\n",ri,rj,rk,pl);
              myexit(29533246346);
            }
#endif

          }

          // copy from lower side to upper boundary zones
          ri=i;
          rj=rjin;
          rk=k;
          LOOPBOUND2OUT PBOUNDLOOP(pliter,pl){
            MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj+(j-N2),rk,pl);

#if(DEBUGINOUTLOOPS)  
            dualfprintf(fail_file,"OUTER X2: ispstag=%d pl=%d :: ri=%d rj=%d rk=%d (otherrj=%d) i=%d j=%d k=%d\n",ispstag,pl,ri,rj,rk,rj+(j-N2),i,j,k);
            dualfprintf(fail_file,"ref: %g\n",MACP0A1(prim,ri,rj+(j-N2),rk,pl));
            if(!isfinite(MACP0A1(prim,ri,rj+(j-N2),rk,pl))){
              dualfprintf(fail_file,"INNER X2: caught copying nan ri=%d rj=%d rk=%d pl=%d\n",ri,rj,rk,pl);
              myexit(3294863498634);
            }
#endif

          }
        }
      }


    }
    else{
      dualfprintf(fail_file,"Shouldn't be here in bounds\n");
      myexit(2946848);
    }


  }// end parallel region

  return(0);
}






/// X3 inner OUTFLOW/FIXEDOUTFLOW
int bound_x3dn_outflow_simple(
                              int boundstage, int finalstep, SFTYPE boundtime, int whichdir, int boundvartype, int *dirprim, int ispstag, FTYPE (*prim)[NSTORE2][NSTORE3][NPR],
                              int *inboundloop,
                              int *outboundloop,
                              int *innormalloop,
                              int *outnormalloop,
                              int (*inoutlohi)[NUMUPDOWN][NDIM],
                              int riin, int riout, int rjin, int rjout, int rkin, int rkout,
                              int *dosetbc,
                              int enerregion,
                              int *localenerpos
                              )
{



#pragma omp parallel  // assume don't require EOS
  {
    int i,j,k,pl,pliter;
    int localj1,globalj1;
    int localk2,globalk2;
    int rk1,rk2;
    struct of_geom geom[NPR],rgeom[NPR];
    FTYPE vcon[NDIM]; // coordinate basis vcon
#if(WHICHVEL==VEL3)
    int failreturn;
#endif
    int ri, rj, rk; // reference i,j,k
    FTYPE prescale[NPR];
    int jj,kk;
    struct of_geom geomdontuse[NPR];
    struct of_geom *ptrgeom[NPR];
    struct of_geom rgeomdontuse[NPR];
    struct of_geom *ptrrgeom[NPR];


    // assign memory
    PALLLOOP(pl){
      ptrgeom[pl]=&(geomdontuse[pl]);
      ptrrgeom[pl]=&(rgeomdontuse[pl]);
    }


    if((BCtype[X3DN]==OUTFLOW)||(BCtype[X3DN]==FIXEDOUTFLOW)||(BCtype[X1DN]==FREEOUTFLOW)){


      if ( (totalsize[3]>1) && (mycpupos[3] <= 0)) {
        /* inner r boundary condition: u, just copy */

        OPENMPBCLOOPVARSDEFINELOOPX3DIR; OPENMPBCLOOPSETUPLOOPX3DIR;
        //////// LOOPX3dir{
#pragma omp for schedule(OPENMPSCHEDULE(),OPENMPCHUNKSIZE(blocksize))
        OPENMPBCLOOPBLOCK{
          OPENMPBCLOOPBLOCK2IJKLOOPX3DIR(i,j);



          ri=i;
          rj=j;
          rk=rkin;


          PALLLOOP(pl) get_geometry(ri, rj, rk, dirprim[pl], ptrrgeom[pl]);

          LOOPBOUND3IN{ // bound entire region inside non-evolved portion of grid
            PBOUNDLOOP(pliter,pl) MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj,rk,pl);
          }




          if(ispstag==0){

            if((BCtype[X3DN]==OUTFLOW)||(BCtype[X3DN]==FIXEDOUTFLOW)){
              // GODMARK: assume all velocities at same location when doing inflow check
              LOOPBOUND3IN{
#if(WHICHVEL==VEL4)
                get_geometry(i, j, k, dirprim[U3], ptrgeom[U3]);
                inflow_check_4vel(3,MAC(prim,i,j,k),NULL,ptrgeom[U3], 0) ;
#elif(WHICHVEL==VEL3)
                get_geometry(i, j, k, dirprim[U3], ptrgeom[U3]);
                inflow_check_3vel(3,MAC(prim,i,j,k),NULL,ptrgeom[U3], 0) ;
                // projection may not preserve u^t to be real and rho>rhoscal u>uuscal
#if(JONCHECKS)
                if(jonchecks){
                  //fixup1zone(0,MAC(prim,i,j,k),ptrgeom[U3],0);
                  failreturn=check_pr(MAC(prim,i,j,k),MAC(prim,i,j,k),ptrgeom[U3],-3);
                  if(failreturn){
                    dualfprintf(fail_file,"Bad boundary zone, couldn't fix: i=%d j=%d k=%d\n",startpos[1]+i,startpos[2]+j,startpos[3]+k);
                    if (fail(i,j,k,FAIL_BCFIX) >= 1) return (1);
                  }
                }
#endif
#elif(WHICHVEL==VELREL4)
                get_geometry(i,j,k,dirprim[U3],ptrgeom[U3]) ;
                inflow_check_rel4vel(3,MAC(prim,i,j,k),NULL,ptrgeom[U3],0) ;
                if(limit_gamma(0,GAMMAMAX,GAMMAMAXRAD,MAC(prim,i,j,k),NULL,ptrgeom[U3],0)>=1)
                  FAILSTATEMENT("bounds.c:bound_prim()", "limit_gamma()", 1);
#endif 
              }
            } // end if not allowing inflow
          }


        }// end 1 2

      }// end if mycpupos[2]==0



    }
    else{
      dualfprintf(fail_file,"Shouldn't be here in bounds\n");
      myexit(312475849);
    }


  }// end parallel region


  return(0);
}

/// X3 outer OUTFLOW/FIXEDOUTFLOW
int bound_x3up_outflow_simple(
                              int boundstage, int finalstep, SFTYPE boundtime, int whichdir, int boundvartype, int *dirprim, int ispstag, FTYPE (*prim)[NSTORE2][NSTORE3][NPR],
                              int *inboundloop,
                              int *outboundloop,
                              int *innormalloop,
                              int *outnormalloop,
                              int (*inoutlohi)[NUMUPDOWN][NDIM],
                              int riin, int riout, int rjin, int rjout, int rkin, int rkout,
                              int *dosetbc,
                              int enerregion,
                              int *localenerpos
                              )
{




#pragma omp parallel  // assume don't require EOS
  {

    int i,j,k,pl,pliter;
    int localk1,globalk1;
    int localk2,globalk2;
    int rk1,rk2;
    FTYPE vcon[NDIM]; // coordinate basis vcon
#if(WHICHVEL==VEL3)
    int failreturn;
#endif
    int ri, rj, rk; // reference i,j,k
    FTYPE prescale[NPR];
    int jj,kk;
    struct of_geom geomdontuse[NPR];
    struct of_geom *ptrgeom[NPR];
    struct of_geom rgeomdontuse[NPR];
    struct of_geom *ptrrgeom[NPR];

    // assign memory
    PALLLOOP(pl){
      ptrgeom[pl]=&(geomdontuse[pl]);
      ptrrgeom[pl]=&(rgeomdontuse[pl]);
    }


  
    if((BCtype[X3UP]==OUTFLOW)||(BCtype[X3UP]==FIXEDOUTFLOW)||(BCtype[X3UP]==FREEOUTFLOW)){

      // outer r BC:
      if ( (totalsize[3]>1) && (mycpupos[3] == ncpux3 - 1) ) {


        OPENMPBCLOOPVARSDEFINELOOPX3DIR; OPENMPBCLOOPSETUPLOOPX3DIR;
        //////// LOOPX3dir{
#pragma omp for schedule(OPENMPSCHEDULE(),OPENMPCHUNKSIZE(blocksize))
        OPENMPBCLOOPBLOCK{
          OPENMPBCLOOPBLOCK2IJKLOOPX3DIR(i,j);


          ri=i;
          rj=j;
          rk=rkout;

          PALLLOOP(pl) get_geometry(ri, rj, rk, dirprim[pl], ptrrgeom[pl]);

          LOOPBOUND3OUT PBOUNDLOOP(pliter,pl) MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj,rk,pl);





          if(ispstag==0){

            if((BCtype[X3UP]==OUTFLOW)||(BCtype[X3UP]==FIXEDOUTFLOW)){

              LOOPBOUND3OUT{
#if(WHICHVEL==VEL4)
                get_geometry(i, j, k, dirprim[U3], ptrgeom[U3]);
                inflow_check_4vel(3,MAC(prim,i,j,k),NULL,ptrgeom[U3],0) ;
#elif(WHICHVEL==VEL3)
                get_geometry(i, j, k, dirprim[U3], ptrgeom[U3]);
                inflow_check_3vel(3,MAC(prim,i,j,k),NULL,ptrgeom[U3],0) ;
                // projection may not preserve u^t to be real and rho>rhoscal u>uuscal
#if(JONCHECKS)
                if(jonchecks){
                  //fixup1zone(0,MAC(prim,i,j,k),ptrgeom[U3],0);
                  failreturn=check_pr(MAC(prim,i,j,k),MAC(prim,i,j,k),ptrgeom[U3],-3);
                  if(failreturn){
                    dualfprintf(fail_file,"Bad boundary zone, couldn't fix: i=%d j=%d k=%d\n",startpos[1]+i,startpos[2]+j,startpos[3]+k);
                    if (fail(i,j,k,FAIL_BCFIX) >= 1) return (1);
                  }
                }
#endif
#elif(WHICHVEL==VELREL4)
                get_geometry(i,j,k,dirprim[U3],ptrgeom[U3]) ;
                inflow_check_rel4vel(3,MAC(prim,i,j,k),NULL,ptrgeom[U3],0) ;
                if(limit_gamma(0,GAMMAMAX,GAMMAMAXRAD,MAC(prim,i,j,k),NULL,ptrgeom[U3], 0)>=1)
                  FAILSTATEMENT("bounds.c:bound_prim()", "limit_gamma()", 2);
#endif 
              }// end over i
            }// end if not allowing inflow

          }



        }// end 1 2
      }// end if mycpu is correct

    }
    else{
      dualfprintf(fail_file,"Shouldn't be here in bounds\n");
      myexit(315875850);
    }

  }// end parallel region


  return(0);
}




















/// X3 inner periodic
int bound_x3_periodic(
                      int boundstage, int finalstep, SFTYPE boundtime, int whichdir, int boundvartype, int *dirprim, int ispstag, FTYPE (*prim)[NSTORE2][NSTORE3][NPR],
                      int *inboundloop,
                      int *outboundloop,
                      int *innormalloop,
                      int *outnormalloop,
                      int (*inoutlohi)[NUMUPDOWN][NDIM],
                      int riin, int riout, int rjin, int rjout, int rkin, int rkout,
                      int *dosetbc,
                      int enerregion,
                      int *localenerpos
                      )
{



#pragma omp parallel  // assume don't require EOS
  {
    int i,j,k,pl,pliter;
    FTYPE vcon[NDIM]; // coordinate basis vcon
#if(WHICHVEL==VEL3)
    int failreturn;
#endif
    int ri, rj, rk; // reference i,j,k
    FTYPE prescale[NPR];
    int jj,kk;


    if( (BCtype[X3DN]==PERIODIC)&&(BCtype[X3UP]==PERIODIC) ){


      // periodic x3
      if ( (totalsize[3]>1) && (mycpupos[3] == 0)&&(mycpupos[3] == ncpux3 - 1) ) {
        // just copy from one side to another

        //// LOOPX3dir{

        OPENMPBCLOOPVARSDEFINELOOPX3DIR; OPENMPBCLOOPSETUPLOOPX3DIR;
#pragma omp for schedule(OPENMPSCHEDULE(),OPENMPCHUNKSIZE(blocksize))
        OPENMPBCLOOPBLOCK{
          OPENMPBCLOOPBLOCK2IJKLOOPX3DIR(i,j);


          // copy from upper side to lower boundary zones
          ri=i;
          rj=j;
          rk=rkout;
          LOOPBOUND3IN PBOUNDLOOP(pliter,pl){
            MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj,rk+1+k,pl);

     
#if(DEBUGINOUTLOOPS)  
            dualfprintf(fail_file,"INNER X3: ispstag=%d  pl=%d :: ri=%d rj=%d rk=%d (otherrk=%d) i=%d j=%d k=%d\n",ispstag,pl,ri,rj,rk,rk+SHIFT3+k,i,j,k);
            if(!isfinite(MACP0A1(prim,ri,rj,rk+SHIFT3+k,pl))){
              dualfprintf(fail_file,"INNER X3: caught copying nan ri=%d rj=%d rk=%d pl=%d\n",ri,rj,rk,pl);
            }
#endif

          }

          // copy from lower side to upper boundary zones
          ri=i;
          rj=j;
          rk=rkin;
          LOOPBOUND3OUT PBOUNDLOOP(pliter,pl){
            MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj,rk+(k-N3),pl);

#if(DEBUGINOUTLOOPS)  
            dualfprintf(fail_file,"OUTER X3: ispstag=%d pl=%d :: ri=%d rj=%d rk=%d (otherrk=%d) i=%d j=%d k=%d\n",ispstag,pl,ri,rj,rk,rk+(k-N3),i,j,k);
            if(!isfinite(MACP0A1(prim,ri,rj,rk+(k-N3),pl))){
              dualfprintf(fail_file,"INNER X3: caught copying nan ri=%d rj=%d rk=%d pl=%d\n",ri,rj,rk,pl);
            }
#endif

          }
        }
      }


    }
    else{
      dualfprintf(fail_file,"Shouldn't be here in bounds\n");
      myexit(3946851);
    }


  }// end parallel region

  return(0);
}




/// X1 inner R0SING
int bound_x1dn_r0singfixinterior(
                                 int boundstage, int finalstep, SFTYPE boundtime, int whichdir, int boundvartype, int *dirprim, int ispstag, FTYPE (*prim)[NSTORE2][NSTORE3][NPR],
                                 int *inboundloop,
                                 int *outboundloop,
                                 int *innormalloop,
                                 int *outnormalloop,
                                 int (*inoutlohi)[NUMUPDOWN][NDIM],
                                 int riin, int riout, int rjin, int rjout, int rkin, int rkout,
                                 int *dosetbc,
                                 int enerregion,
                                 int *localenerpos
                                 )
{
  int i,j,k,pl,pliter;
  int locali1,globali1;
  int locali2,globali2;
  int ri1,ri2;
  FTYPE vcon[NDIM]; // coordinate basis vcon
#if(WHICHVEL==VEL3)
  int failreturn;
#endif
  int ri, rj, rk; // reference i,j,k
  FTYPE prescale[NPR];
  int horizonti;
  int jj,kk;



  if(  (totalsize[1]>1) && BCtype[X1DN]==R0SING){ // global condition that all CPUs know about

    /////////////////
    //
    // now deal with region interior to the horizon
    // This just makes values reasonable for diagnostics to be ignorant of loop ranges -- results are NOT used! -- no FLUXCTSTAG issues
    // similar to bound_spacetime_inside_horizon() in metric.c

  
    horizonti=N1*horizoncpupos1+horizoni;

    if(horizonti>0){ // global condition that all CPUs know about
      // for self-gravity, only loop over region outside horizon
      enerregion=OUTSIDEHORIZONENERREGION;
      enerpos=enerposreg[enerregion];


      // copy from very outer boundary or from location on grid defined by where last ghost cell is inside horizon

      // this doesn't do anything to cells inside horizon but outside fake region
      // apparently in this case uu1>0 even though inside the horizon
      globali1=N1*horizoncpupos1+horizoni-N1BND;
      if(globali1<startpos[1]-N1BND) locali1=-N1BND;
      else if(globali1>endpos[1]+N1BND-1) locali1=N1+N1BND-1;
      else locali1=horizoni-N1BND;
      ri1=locali1;



      // include all zones inside horizon as outflow so remove any peak that was accreted as black hole
      // flux through horizon of mass should be consistent with either method, but seems more reasonable to do below
      globali2=N1*horizoncpupos1+horizoni;
      if(globali2<startpos[1]) locali2=0;
      else if(globali2>endpos[1]-1) locali2=N1-1;
      else locali2=horizoni;
      ri2=locali2;
      // GODMARK: somehow leads to density sticking to value despite much lower active density


      LOOPF{

        rj=j;
        rk=k;
      
        //      if(WITHINENERREGION(enerpos,i,j,k)){
        // then do nothing
        //      }
        //else{
        // assume horizon on negative side of "i" so don't modify right side of "i" that happens to be in the outer radial boundary

        if(i < globali1-startpos[1]){
          // then inside horizon
   
          // set primitives to be trivialized
 
          PBOUNDLOOP(pliter,pl) MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri1,rj,rk,pl);

          // reset pflag in case old failure inside horizon
#if(UTOPRIMADJUST==UTOPRIMAVG)
          GLOBALMACP0A1(pflag,i,j,k,FLAGUTOPRIMFAIL)=UTOPRIMNOFAIL;
#endif


          if(ispstag==0){
            // making it small artificially forces timestep to be small since timestep still limited within fake boundary region
            //   MACP0A1(prim,i,j,k,RHO) = SMALL;
            // assumed acting on relative 4-velocity that stays physical no matter what
            if(MACP0A1(prim,i,j,k,U1)>0) MACP0A1(prim,i,j,k,U1)=-0.5*(fabs(MACP0A1(prim,ri1,rj,rk,U1))+fabs(MACP0A1(prim,ri1+1,rj,rk,U1)));
          }
        }

        if(0 && i < globali2-startpos[1]){
          // then on or inside horizon and inside N1BND more grid cells for interpolation
   
          if(ispstag==0){
            // assumed acting on relative 4-velocity that stays physical no matter what
            if(MACP0A1(prim,i,j,k,U1)>0) MACP0A1(prim,i,j,k,U1)=-0.5*(fabs(MACP0A1(prim,ri1,rj,rk,U1))+fabs(MACP0A1(prim,ri1+1,rj,rk,U1)));
          }

        }
        //}
      }


    }
  }
  else{
    dualfprintf(fail_file,"Shouldn't be here in bounds\n");
    myexit(3946852);
  }



  return(0);
}







/// Check that boundary conditions were set properly
int bound_checks1(
                  int boundstage, int finalstep, SFTYPE boundtime, int whichdir, int boundvartype, int *dirprim, int ispstag, FTYPE (*prim)[NSTORE2][NSTORE3][NPR],
                  int *inboundloop,
                  int *outboundloop,
                  int *innormalloop,
                  int *outnormalloop,
                  int (*inoutlohi)[NUMUPDOWN][NDIM],
                  int riin, int riout, int rjin, int rjout, int rkin, int rkout,
                  int *dosetbc,
                  int enerregion,
                  int *localenerpos
                  )
{
  int i,j,k,pl,pliter;
  int locali1,globali1;
  int locali2,globali2;
  int ri1,ri2;
  FTYPE vcon[NDIM]; // coordinate basis vcon
#if(WHICHVEL==VEL3)
  int failreturn;
#endif
  int ri, rj, rk; // reference i,j,k
  FTYPE prescale[NPR];
  int horizonti;
  int jj,kk;



#if(PRODUCTION==0)
  // can only check after all directions done, and we assume whichdir==3 last to be done
  int trigger=0;
  if(ispstag){
    ZSLOOP(inoutlohi[POINTDOWN][POINTDOWN][1], inoutlohi[POINTUP][POINTUP][1],inoutlohi[POINTDOWN][POINTDOWN][2], inoutlohi[POINTUP][POINTUP][2],inoutlohi[POINTDOWN][POINTDOWN][3], inoutlohi[POINTUP][POINTUP][3]){
      // Can't use FULLLOOP since different boundary types go different depths into boundary cells
      //      PALLLOOP(pl){
      PBOUNDLOOP(pliter,pl){
        // for staggered field, avoid inner-most cell since isn't needed or computed and so can be NaN
        if(pl==B1 && i>=-N1BND+SHIFT1 || pl==B2 && j>=-N2BND+SHIFT2 || pl==B3 && k>=-N3BND+SHIFT3){
          if(!finite(MACP0A1(prim,i,j,k,pl))){
            trigger++;
            dualfprintf(fail_file,"whichdir=%d ispstag=%d trigger=%d :: BC didn't set properly: #1: i=%d j=%d k=%d ti=%d tj=%d tk=%d pl=%d\n",whichdir,ispstag,trigger,i,j,k,startpos[1]+i,startpos[2]+j,startpos[3]+k,pl);
          }
        }
      }
    }
  }
  else{
    ZSLOOP(inoutlohi[POINTDOWN][POINTDOWN][1], inoutlohi[POINTUP][POINTUP][1],inoutlohi[POINTDOWN][POINTDOWN][2], inoutlohi[POINTUP][POINTUP][2],inoutlohi[POINTDOWN][POINTDOWN][3], inoutlohi[POINTUP][POINTUP][3]){
      //      PALLLOOP(pl){
      PBOUNDLOOP(pliter,pl){
        if(!finite(MACP0A1(prim,i,j,k,pl))){
          trigger++;
          dualfprintf(fail_file,"whichdir=%d ispstag=%d trigger=%d :: BC didn't set properly: #1: i=%d j=%d k=%d ti=%d tj=%d tk=%d pl=%d\n",whichdir,ispstag,trigger,i,j,k,startpos[1]+i,startpos[2]+j,startpos[3]+k,pl);
        }
      }
    }
  }
  //  if(trigger>0) myexit(92489346); // first calls to bound will have no field, for example, so can't exit
#endif



  return (0);
}





/// OPTMARK: all get_geometries, etc. could be simplified if take advantage of fact that only really 2 cases: all CENT or CENT for all except B's.
/// otherwise extrapfunc() and poledeath()'s get_geometry() dominates CPU time when few active cells or many boundary cells
//
/// boundary = X1DN or X1UP
/// assume if ispstag==1 then only doing field part -- otherwise logic would get more complicated
int extrapfunc(int boundary, int j,int k,
               int boundstage, int finalstep, SFTYPE boundtime, int whichdir, int boundvartype, int *dirprim, int ispstag, FTYPE (*prim)[NSTORE2][NSTORE3][NPR],
               int *inboundloop,
               int *outboundloop,
               int *innormalloop,
               int *outnormalloop,
               int (*inoutlohi)[NUMUPDOWN][NDIM],
               int riin, int riout, int rjin, int rjout, int rkin, int rkout,
               int *dosetbc,
               int enerregion,
               int *localenerpos
               )
{
  int i,pl,pliter;
  int ri,rj,rk;
  int iloopstart,iloopend,iloopstep;
  int ri2,ri3;
  // for Bd3 copy
  FTYPE Bd3,Bd3ri2,Bd3ri3;
  int jj;
  FTYPE Bu1,Bu2,gcon03,gcon13,gcon23,gcon33;
  FTYPE gcov01,gcov02,gcov11,gcov12,gcov21,gcov22,gcov03,gcov13,gcov23;
  // Mdot copy
  FTYPE Mdot,ucon[NDIM],uconref[NDIM],uradconref[NDIM];
  FTYPE Mraddot,uradcon[NDIM];
  FTYPE Xr[NPR][NDIM],Vr[NPR][NDIM],X[NPR][NDIM],V[NPR][NDIM];
  FTYPE primtemp[NPR];
  FTYPE *ucontouse, ucon2[NDIM];
  int itervphi;
  FTYPE uconrefri2[NDIM],uradconrefri2[NDIM];
  FTYPE Mdotri2;
  FTYPE uconrefri3[NDIM],uradconrefri3[NDIM];
  FTYPE othersref[NUMOTHERSTATERESULTS],othersrefri2[NUMOTHERSTATERESULTS],othersrefri3[NUMOTHERSTATERESULTS],others[NUMOTHERSTATERESULTS],othersrefnew[NUMOTHERSTATERESULTS];
  FTYPE othersradref[NUMOTHERSTATERESULTS],othersradrefri2[NUMOTHERSTATERESULTS],othersradrefri3[NUMOTHERSTATERESULTS],othersrad[NUMOTHERSTATERESULTS],othersradrefnew[NUMOTHERSTATERESULTS];
  FTYPE Mdotri3;
  FTYPE Dqp,Dqm,Dqc,dqMdot;
  FTYPE myMdot;
  FTYPE dq[NPR];
  FTYPE dqucon[NDIM];
  FTYPE dqBd3,myBd3;
  FTYPE dqgdetpl[NPR];
  FTYPE dqorthopl[NPR];
  FTYPE dqlogdensity[NPR];
  FTYPE uconreftouse[NDIM],uradconreftouse[NDIM];
  FTYPE xfrac,yfrac;
  FTYPE ftemp;
  FTYPE signdq;
  FTYPE xdqfrac,ydqfrac;
  FTYPE ftemp2,linearvalue,expvalue;
  FTYPE D0,uconrefnew[NDIM],uradconrefnew[NDIM];
  FTYPE mydqlog;
  FTYPE igdetnosing;
  struct of_geom geomdontuse[NPR];
  struct of_geom *ptrgeom[NPR];
  struct of_geom rgeomdontuse[NPR];
  struct of_geom *ptrrgeom[NPR];
  struct of_geom ri2geomdontuse[NPR];
  struct of_geom *ptrri2geom[NPR];
  struct of_geom ri3geomdontuse[NPR];
  struct of_geom *ptrri3geom[NPR];


  // assign memory
  PALLLOOP(pl){
    ptrgeom[pl]=&(geomdontuse[pl]);
    ptrrgeom[pl]=&(rgeomdontuse[pl]);
    ptrri2geom[pl]=&(ri2geomdontuse[pl]);
    ptrri3geom[pl]=&(ri3geomdontuse[pl]);
  }


  rj=j;
  rk=k;


  // setup multiple reference points
  if(boundary==X1DN){
    ri = riin;
    ri2=ri+1;
    ri3=ri+2;
    // iterate up (due to use of single loop form)
    iloopstart=LOWERBOUND1;
    iloopend=ri-1;
    iloopstep=1;
    signdq=1.0;
  }
  else if(boundary==X1UP){
    ri = riout;
    ri2=ri-1;
    ri3=ri-2;
    // iterate up (due to use of single loop form)
    iloopstart=ri+1;
    iloopend=UPPERBOUND1;
    iloopstep=1;
    signdq=-1.0;
  }
  else{
    dualfprintf(fail_file,"extrapfunc not setup for this boundary = %d\n",boundary);
    myexit(811751);
  }



  /////////////
  //
  // get coordinates of reference location
  //
  /////////////
  PBOUNDLOOP(pliter,pl){
    get_geometry(ri, rj, rk, dirprim[pl], ptrrgeom[pl]);
    get_geometry(ri2, rj, rk, dirprim[pl], ptrri2geom[pl]);
    get_geometry(ri3, rj, rk, dirprim[pl], ptrri3geom[pl]);

    bl_coord_ijk_2(ri,rj,rk,dirprim[pl],Xr[pl],Vr[pl]); // reference locations for B2/U2
  }



  /////////////
  //
  // obtain reference B_\phi
  //
  /////////////
  Bd3=0.0; SLOOPA(jj) Bd3 += MACP0A1(prim,ri,rj,rk,B1+jj-1)*(ptrrgeom[B1+jj-1]->gcov[GIND(3,jj)]);
  Bd3ri2=0.0; SLOOPA(jj) Bd3ri2 += MACP0A1(prim,ri2,rj,rk,B1+jj-1)*(ptrri2geom[B1+jj-1]->gcov[GIND(3,jj)]);
  Bd3ri3=0.0; SLOOPA(jj) Bd3ri3 += MACP0A1(prim,ri3,rj,rk,B1+jj-1)*(ptrri3geom[B1+jj-1]->gcov[GIND(3,jj)]);
  // B_\phi slope
  Dqp=Bd3ri3-Bd3ri2;
  Dqm=Bd3ri2-Bd3;
  Dqc=Bd3ri3-Bd3;
  Dqc*=0.5;
  dqBd3 = signdq*MINMOD(MINMOD(Dqp,Dqm),Dqc);



  ///////////////////////////////////////////
  //
  // reference value for \detg rho u^{x1}
  //
  ///////////////////////////////////////////


  if(ispstag==0){
    ucon_calc(MAC(prim,ri,rj,rk),ptrrgeom[U1],uconref,othersref);
    Mdot = (ptrrgeom[U1]->gdet)*MACP0A1(prim,ri,rj,rk,RHO)*uconref[1];

    // ri2
    ucon_calc(MAC(prim,ri2,rj,rk),ptrri2geom[U1],uconrefri2,othersrefri2);
    Mdotri2 = (ptrri2geom[U1]->gdet)*MACP0A1(prim,ri2,rj,rk,RHO)*uconrefri2[1];

    // ri3
    ucon_calc(MAC(prim,ri3,rj,rk),ptrri3geom[U1],uconrefri3,othersrefri3);
    Mdotri3 = (ptrri3geom[U1]->gdet)*MACP0A1(prim,ri3,rj,rk,RHO)*uconrefri3[1];

    // Mdot slope
    Dqp=Mdotri3-Mdotri2;
    Dqm=Mdotri2-Mdot;
    Dqc=Mdotri3-Mdot;
    Dqc*=0.5;
    dqMdot = signdq*MINMOD(MINMOD(Dqp,Dqm),Dqc);

    if(EOMRADTYPE!=EOMRADNONE){
      // KORALTODO: Could treat radiation stuff equal to MHD, but here MHD is just getting Mdot, that has no real counterpart for radiation
      ucon_calc(&MACP0A1(prim,ri,rj,rk,URAD1-U1),ptrrgeom[URAD1],uradconref,othersradref);
      ucon_calc(&MACP0A1(prim,ri2,rj,rk,URAD1-U1),ptrri2geom[URAD1],uradconrefri2,othersradrefri2);
      ucon_calc(&MACP0A1(prim,ri3,rj,rk,URAD1-U1),ptrri3geom[URAD1],uradconrefri3,othersradrefri3);
    }

  }



  //////////////////////
  //
  // prim[pl] slope
  //
  //////////////////////
  PBOUNDLOOP(pliter,pl){
    // determine MINM slope for extrapolation
    Dqp=MACP0A1(prim,ri3,rj,rk,pl)-MACP0A1(prim,ri2,rj,rk,pl);
    Dqm=MACP0A1(prim,ri2,rj,rk,pl)-MACP0A1(prim,ri,rj,rk,pl);
    Dqc=MACP0A1(prim,ri3,rj,rk,pl)-MACP0A1(prim,ri,rj,rk,pl);
    Dqc*=0.5;
    dq[pl] = signdq*MINMOD(MINMOD(Dqp,Dqm),Dqc);
  }


  //////////////////////////
  //
  // log(prim[pl]) slope
  //
  //////////////////////////
  PBOUNDLOOP(pliter,pl){
    // determine MINM slope for extrapolation
    Dqp=log(SMALL+fabs(MACP0A1(prim,ri3,rj,rk,pl)))-log(SMALL+fabs(MACP0A1(prim,ri2,rj,rk,pl)));
    Dqm=log(SMALL+fabs(MACP0A1(prim,ri2,rj,rk,pl)))-log(SMALL+fabs(MACP0A1(prim,ri,rj,rk,pl)));
    Dqc=log(SMALL+fabs(MACP0A1(prim,ri3,rj,rk,pl)))-log(SMALL+fabs(MACP0A1(prim,ri,rj,rk,pl)));
    Dqc*=0.5;
    dqlogdensity[pl] = signdq*MINMOD(MINMOD(Dqp,Dqm),Dqc);
  }

  ////////////
  //
  // gdet * prim[pl] slope
  //
  ////////////
  PBOUNDLOOP(pliter,pl){
    // determine MINM slope for extrapolation
    Dqp=(ptrri3geom[pl]->gdet)*MACP0A1(prim,ri3,rj,rk,pl)-(ptrri2geom[pl]->gdet)*MACP0A1(prim,ri2,rj,rk,pl);
    Dqm=(ptrri2geom[pl]->gdet)*MACP0A1(prim,ri2,rj,rk,pl)-(ptrrgeom[pl]->gdet)*MACP0A1(prim,ri,rj,rk,pl);
    Dqc=(ptrri3geom[pl]->gdet)*MACP0A1(prim,ri3,rj,rk,pl)-(ptrrgeom[pl]->gdet)*MACP0A1(prim,ri,rj,rk,pl);
    Dqc*=0.5;
    dqgdetpl[pl] = signdq*MINMOD(MINMOD(Dqp,Dqm),Dqc);
  }

  ////////////
  //
  // sqrt(gv3ii) * prim[pl] slope
  //
  ////////////
  int ddir;
  PBOUNDLOOP(pliter,pl){
    // determine MINM slope for extrapolation
    ddir=0; // default
    if(pl>=U1 || pl<=U3) ddir=pl-U1+1;
    if(pl>=URAD1 || pl<=URAD3) ddir=pl-URAD1+1;
    if(pl>=B1 || pl<=B3) ddir=pl-B1+1;
    Dqp=sqrt(fabs(ptrri3geom[pl]->gcov[GIND(ddir,ddir)]))*MACP0A1(prim,ri3,rj,rk,pl)-sqrt(fabs(ptrri2geom[pl]->gcov[GIND(ddir,ddir)]))*MACP0A1(prim,ri2,rj,rk,pl);
    Dqm=sqrt(fabs(ptrri2geom[pl]->gcov[GIND(ddir,ddir)]))*MACP0A1(prim,ri2,rj,rk,pl)-sqrt(fabs(ptrrgeom[pl]->gcov[GIND(ddir,ddir)]))*MACP0A1(prim,ri,rj,rk,pl);
    Dqc=sqrt(fabs(ptrri3geom[pl]->gcov[GIND(ddir,ddir)]))*MACP0A1(prim,ri3,rj,rk,pl)-sqrt(fabs(ptrrgeom[pl]->gcov[GIND(ddir,ddir)]))*MACP0A1(prim,ri,rj,rk,pl);
    Dqc*=0.5;
    dqorthopl[pl] = signdq*MINMOD(MINMOD(Dqp,Dqm),Dqc);
  }


  //////////////////////
  //
  // u^i slope
  //
  //////////////////////
  if(ispstag==0){
    DLOOPA(jj){
      // determine MINM slope for extrapolation
      Dqp=uconrefri3[jj]-uconrefri2[jj];
      Dqm=uconrefri2[jj]-uconref[jj];
      Dqc=uconrefri3[jj]-uconref[jj];
      Dqc*=0.5;
      dqucon[jj] = signdq*MINMOD(MINMOD(Dqp,Dqm),Dqc);
    }

    // get fraction of farther away reference value to use
    // Fraction of normal reference value is determined by how similar u^t is for (e.g. for inner boundary) ri and ri+1
    xfrac = fabs(uconref[TT]-uconrefri2[TT])/uconref[TT];
#define XFRAC1 (0.1) // 0.1 was chosen from experience with BH+torus and what the u^t value was doing at the pole near the horizon -- JCM found once d(u^t)>0.1 then started to grow unbound.  Certainly related to resolution so assume resolving of horizon is generally similar to the 64^2 case with Rout=40 and exp grid
#define YFRAC1 (0.0)
#define XFRAC2 (0.2)
#define YFRAC2 (1.0)
#define YFRAC12(frac) (YFRAC1 + (YFRAC2-YFRAC1)/(XFRAC2-XFRAC1)*(frac-XFRAC1))

    if(xfrac<XFRAC1) yfrac=YFRAC1;
    else if(xfrac<XFRAC2) yfrac=YFRAC12(xfrac);
    else yfrac=YFRAC2;


#define XDQFRAC1 (0.1)
#define YDQFRAC1 (0.0)
#define XDQFRAC2 (0.2)
#define YDQFRAC2 (1.0)
#define YDQFRAC12(frac) (YDQFRAC1 + (YDQFRAC2-YDQFRAC1)/(XDQFRAC2-XDQFRAC1)*(frac-XDQFRAC1))

    // limit slope in extrapolation if excessive slope
    xdqfrac = fabs(uconref[TT]-uconrefri2[TT])/uconref[TT];
    if(xdqfrac<XDQFRAC1) ydqfrac=YDQFRAC1;
    else if(xdqfrac<XDQFRAC2) ydqfrac= YDQFRAC12(xdqfrac);
    else ydqfrac=YDQFRAC2;
    
    // modify dqucon based upon ydqfrac
    // Uses original MINM slope unless slope is too large, then start to decrease to no slope
    // only apply to velocity related slopes
    DLOOPA(jj){
      dqucon[jj] = dqucon[jj]*(1.0-ydqfrac);
      dq[UU+jj] = dq[UU+jj]*(1.0-ydqfrac);
      dqlogdensity[UU+jj] = dqlogdensity[UU+jj]*(1.0-ydqfrac);
      dqMdot = dqMdot*(1.0-ydqfrac);
      dqgdetpl[UU+jj] = dqgdetpl[UU+jj]*(1.0-ydqfrac);
    }



  }// end if ispstag==0
  else{
    yfrac=ydqfrac=0.0;
  }







  /////////////////////
  //
  // LOOP over i and pl
  //
  /////////////////////

  LOOPBOUNDGENMORE(i,iloopstart,iloopend,iloopstep){
  


    //////////////////
    //
    // default copy
    //
    //////////////////
    PBOUNDLOOP(pliter,pl) MACP0A1(prim,i,j,k,pl)=MACP0A1(prim,ri,rj,rk,pl);
    
    //////////////////
    //
    // get coordinates of local location for all quantities
    //
    //////////////////
    PBOUNDLOOP(pliter,pl){
      get_geometry(i, j, k, dirprim[pl], ptrgeom[pl]);
      bl_coord_ijk_2(i,j,k,dirprim[pl],X[pl],V[pl]); // reference locations for B2/U2
    }





    ///////////////////////////////
    //
    // NON-magnetic field parts (\rho,u,u^i, etc.)
    //
    ///////////////////////////////
    if(ispstag==0){


      ///////////////////////////////
      //
      // Other Densities
      //
      ///////////////////////////////

      /// did assume densities roughly constant (good for disk, not as good for polar region of mostly radial Bondi-like flow)
      // now focus on accuracy for polar regions to maintain stability (avoid dissipation terms doing funny things)

      // using below Bondi-like scaling with Mdot scaling for ucon leads to space-like answers  Near BH densities should become roughly constant, and this doesn't lead to problems, so use instead
      //   pl=RHO; MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj,rk,pl)*pow(V[pl][1]/Vr[pl][1],-3.0/2.0);
      //   pl=UU;  MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj,rk,pl)*pow(V[pl][1]/Vr[pl][1],-5.0/2.0);

#define POWEREXTRAFRAC (0.1)
#define POWERRATIO (1.0+POWEREXTRAFRAC) // ratio of densities not allow to go bigger than this when using dqlogdensity


#if(1) ///////////// BIG IF

      PBOUNDLOOP(pliter,pl){
        // MUST BE POSITIVE DEFINITE!!!
        if(pl!=B1 && pl!=B2 && pl!=B3 && pl!=URAD1 && pl!=URAD2 && pl!=URAD3 && SCALARPL(pl)==0){

          // only use linear if exponentiation causes growth of value, not decreasion
          ftemp = exp(-signdq*dqlogdensity[pl]) - POWERRATIO;

          // limit interpolation strength to fixed log-slope
          if(ftemp>=0.0) mydqlog=log(POWERRATIO)/(-signdq);
          else mydqlog = dqlogdensity[pl];

          // log extrap (very speculative and can cause problems if used alone when (say) density is super low on ri+1 and relatively high on ri, then i will be super huge
          // should use this when values that go into slope are much different, or equally when dqlogdensity is large
          MACP0A1(prim,i,j,k,pl) = exp(log(SMALL+fabs(MACP0A1(prim,ri,rj,rk,pl))) + mydqlog*(i-ri));

          // DEBUG:
          //   dualfprintf(fail_file,"i=%d j=%d pl=%d ftemp=%21.15g linearvalue=%21.15g expvalue=%21.15g final=%21.15g\n",i,j,pl,ftemp,linearvalue,expvalue,MACP0A1(prim,i,j,k,pl));

        }
      }



#else ///////////// BIG ELSE



      // override using OLD WAY for densities
#if(0)
      // linear extrap (leads to negative values, which can cause problems with flux inversions)
      PBOUNDLOOP(pliter,pl) if(pl==RHO) MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj,rk,pl) + dq[pl]*(i-ri);
      PBOUNDLOOP(pliter,pl) if(pl==UU)  MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj,rk,pl) + dq[pl]*(i-ri);
      PBOUNDLOOP(pliter,pl) if(pl==URAD0)  MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj,rk,pl) + dq[pl]*(i-ri);
#else
      // log extrap
      PBOUNDLOOP(pliter,pl) if(pl==RHO) MACP0A1(prim,i,j,k,pl) = exp(log(SMALL+fabs(MACP0A1(prim,ri,rj,rk,pl))) + dqlogdensity[pl]*(i-ri));
      PBOUNDLOOP(pliter,pl) if(pl==UU)  MACP0A1(prim,i,j,k,pl) = exp(log(SMALL+fabs(MACP0A1(prim,ri,rj,rk,pl))) + dqlogdensity[pl]*(i-ri));
      PBOUNDLOOP(pliter,pl) if(pl==URAD0)  MACP0A1(prim,i,j,k,pl) = exp(log(SMALL+fabs(MACP0A1(prim,ri,rj,rk,pl))) + dqlogdensity[pl]*(i-ri));
#endif


#endif ///////////// BIG ENDIF



   
      ///////////////////////////////
      //
      // Velocity
      //
      ///////////////////////////////

#if(0) ///////////// BIG IF


      // appears too speculative and use of v^3 causes ucon2pr to lead to no solution within boundary conditions -- suggestive of some inconsistency
      //  (primitive can be anything)

      // combined with \rho_0=constant, this implies \detg \rho_0 u^x1 == constant as required for Mdot=constant for radial flow
      //   pl=U1; MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj,rk,pl)*fabs((ptrrgeom[pl]->gdet)/(ptrgeom[pl]->gdet));
      myMdot = Mdot + dqMdot*(i-ri);
      ucon[1] = myMdot/((ptrgeom[U1]->gdet)*MACP0A1(prim,i,j,k,RHO));
      // assume ucon[2] and ucon[3] are just copied directly
      // assume mostly radial flow, but visibly appears like B2 so treat similarly so no large kink in behavior
      ucon[2] = uconref[2] + dqucon[2]*(i-ri);
      // assume v^\phi \sim \Omega doesn't change much
      ucon[3] = uconref[3] + dqucon[3]*(i-ri);

      // using non-computed u^t in ucon2pr means slightly inconsistent with desired u^t[u^i], but assume approximately correct and is sufficient for extrapolation to get primitive
      //   ucon[TT] = uconref[TT];

      // fill so can use standard functions
      primtemp[U1] = ucon[1];
      primtemp[U2] = ucon[2];
      primtemp[U3] = ucon[3];
      // get real ucon with real u^t
      ucon_calc_4vel_bothut(primtemp, ptrgeom[U1], ucon, ucon2, others);
      // now get primitive velocity (choosing 4-velocity branch closest to reference velocity)
      // using the below causes flipping of choice in accretion flow region of boundary conditions due to being too far away from original uconref[TT]
      //   if(fabs(ucon[TT]-uconref[TT])<fabs(ucon2[TT]-uconref[TT])) ucontouse=ucon;
      //   else ucontouse=ucon2;
      ucontouse=ucon;

      /////////////////
      //
      // iterate to get closer to v^\phi\sim constant (safer than setting v^i directly and using vcon2pr())
      //
      /////////////////

      for(itervphi=0;itervphi<=NUMITERVPHI;itervphi++){
        // assume v^\phi \sim \Omega doesn't change much
        primtemp[U3] = uconref[3]/uconref[TT]*ucontouse[TT];
        // get real ucon with real u^t
        ucon_calc_4vel_bothut(primtemp, ptrgeom[U1], ucon, ucon2, others);
        // now get primitive velocity (choosing 4-velocity branch closest to reference velocity)
        //     if(fabs(ucon[TT]-uconref[TT])<fabs(ucon2[TT]-uconref[TT])) ucontouse=ucon;
        //     else ucontouse=ucon2;
        ucontouse=ucon;
      }

      /////////////////////////
      // get final primitive from ucon
      ucon2pr(WHICHVEL,ucontouse,ptrgeom[U1],MAC(prim,i,j,k)); // fills only U1,U2,U3


#elif(0) ///////////// BIG ELIF

      // GODMARK: Was causing problems for Rebecca


      // BH-pole corner angular sucking drive u^t>>0 and then failures occur
      // avoid exaggerating via unwanted radial sucking by using reference value with

      // whether to conserve (at least) D=\rho_0 u^t when modifying \gamma
      // see notes in fixup.c for limit_gamma() regarding why this is not a good idea
#define DO_CONSERVE_D_INBOUNDS 0 // CHANGINGMARK



#if(DO_CONSERVE_D_INBOUNDS)
      // GODMARK: here we actually modify active values of quantities (should we preserve D=\rho_0 u^t ? -- i.e. change \rho_0?)
      // This correction comes after any other velocity modifications
      // of all conservation laws, at least conserve particle number
      D0 = MACP0A1(prim,ri,rj,rk,RHO)*uconref[TT];
#endif

      PBOUNDLOOP(pliter,pl){
        if(pl==U1 || pl==U2 || pl==U3 || pl==URAD1 || pl==URAD2 || pl==URAD3){
          
          // switch away from using near-BC value as reference if going bad since don't want to exaggerate it
          ftemp = MACP0A1(prim,ri,rj,rk,pl)*(1.0-yfrac) + MACP0A1(prim,ri2,rj,rk,pl)*yfrac;
          // interpolate
          MACP0A1(prim,i,j,k,pl) = (ftemp + dq[pl]*(i-ri));


          // dualfprintf(fail_file,"i=%d j=%d k=%d pl=%d ftemp=%21.15g yfrac=%21.15g dq[pl]=%21.15g i=%d ri=%d ri2=%d ri3=%d rj=%d rk=%d :: prim=%21.15g pri2=%21.15g pri3=%21.15g\n",i,j,k,pl,ftemp,yfrac,dq[pl],i,ri,ri2,ri3,rj,rk,MACP0A1(prim,i,j,k,pl),MACP0A1(prim,ri2,rj,rk,pl),MACP0A1(prim,ri3,rj,rk,pl)); // CHANGINGMARK



          if(V[pl][RR]<RADIUSTOAVOIDRADIALSUCK){
            // only do this if near a BH
            // also use yfrac to reset on-grid value since apparently it's going bad
            // this also keeps interpolation scheme passing through to boundary and so avoiding unwanted dissipation that can evolve flow away from sanity
            // linear extrap
            // GODMARK: Should probably make sure that u^r doesn't change sign?!
            MACP0A1(prim,ri,rj,rk,pl) = MACP0A1(prim,ri,rj,rk,pl)*(1.0-yfrac) + (MACP0A1(prim,ri2,rj,rk,pl) + dq[pl]*(ri-(ri2)))*yfrac;
          }

        }// end over velocities
      }
#if(DO_CONSERVE_D_INBOUNDS)
      // get new u^t
      ucon_calc(MAC(prim,ri,rj,rk),ptrrgeom[U1],uconrefnew, othersrefnew);
      // recompute \rho_0 to conserve particle number (generally will increase \rho_0)
      MACP0A1(prim,ri,rj,rk,RHO) = D0/uconrefnew[TT];
#endif




#elif(0) ///////////// BIG ELIF
      // linear extrap
      PBOUNDLOOP(pliter,pl){
        if(pl==U1 || pl==U2 || pl==U3 || pl==URAD1 || pl==URAD2 || pl==URAD3){
          
          // switch away from using near-BC value as reference if going bad since don't want to exaggerate it
          ftemp = MACP0A1(prim,ri,rj,rk,pl)*(1.0-yfrac) + MACP0A1(prim,ri3,rj,rk,pl)*yfrac;
          // interpolate
          MACP0A1(prim,i,j,k,pl) = ftemp + dq[pl]*(i-ri);
        }
      }


#elif(1) ///////////// BIG ELIF
      // linear extrap for velocities
      PBOUNDLOOP(pliter,pl){
        if(pl==U1 || pl==U2 || pl==U3 || pl==URAD1 || pl==URAD2 || pl==URAD3){
          //if(pl==U1 || pl==U2 || pl==U3){
          ftemp = MACP0A1(prim,ri,rj,rk,pl);
          // interpolate
          MACP0A1(prim,i,j,k,pl) = ftemp + dq[pl]*(i-ri);
        }
      
        if(0){
          // SUPERMARK: KORALTODO
          if(pl==URAD1 || pl==URAD2 || pl==URAD3){
            ftemp = MACP0A1(prim,ri,rj,rk,pl);
            // interpolate
            MACP0A1(prim,i,j,k,pl) = ftemp;
          }
        }

      }


#if(0)
      ucon_calc(&MACP0A1(prim,ri,rj,rk,0),ptrgeom[U1],ucon,others);
      if(boundary==X1DN && (uconref[1]>0.0 || ucon[1]>0.0)) MACP0A1(prim,i,j,k,U1)=0.0;
      if(boundary==X1UP && (uconref[1]<0.0 || ucon[1]<0.0)) MACP0A1(prim,i,j,k,U1)=0.0;
      if(boundary==X2DN && (uconref[2]>0.0 || ucon[2]>0.0)) MACP0A1(prim,i,j,k,U2)=0.0;
      if(boundary==X2UP && (uconref[2]<0.0 || ucon[2]<0.0)) MACP0A1(prim,i,j,k,U2)=0.0;
      if(boundary==X3DN && (uconref[3]>0.0 || ucon[3]>0.0)) MACP0A1(prim,i,j,k,U3)=0.0;
      if(boundary==X3UP && (uconref[3]<0.0 || ucon[3]<0.0)) MACP0A1(prim,i,j,k,U3)=0.0;

      if(EOMRADTYPE!=EOMRADNONE){
        ucon_calc(&MACP0A1(prim,ri,rj,rk,URAD1-U1),ptrgeom[URAD1],uradcon,othersrad);
        if(boundary==X1DN && (uradconref[1]>0.0 || uradcon[1]>0.0)) MACP0A1(prim,i,j,k,URAD1)=0.0;
        if(boundary==X1UP && (uradconref[1]<0.0 || uradcon[1]<0.0)) MACP0A1(prim,i,j,k,URAD1)=0.0;
        if(boundary==X2DN && (uradconref[2]>0.0 || uradcon[2]>0.0)) MACP0A1(prim,i,j,k,URAD2)=0.0;
        if(boundary==X2UP && (uradconref[2]<0.0 || uradcon[2]<0.0)) MACP0A1(prim,i,j,k,URAD2)=0.0;
        if(boundary==X3DN && (uradconref[3]>0.0 || uradcon[3]>0.0)) MACP0A1(prim,i,j,k,URAD3)=0.0;
        if(boundary==X3UP && (uradconref[3]<0.0 || uradcon[3]<0.0)) MACP0A1(prim,i,j,k,URAD3)=0.0;
      }
#endif
      

#endif    ///////////// BIG ENDIF


    } // end if ispstag==0



    ///////////////////////////////
    //
    // MAGNETIC FIELD
    //
    ///////////////////////////////

    ////////
    //
    // assume \detg B^x1 == constant (well, extrapolated now)
    //
    // GODMARK: Should probably make sure that B^r and B^\phi don't change sign! (well, maybe at least B^r)
    // Should probably preserve signature of B^\phi/B^r = -\Omega_F/c -- suggests interpolating B^\phi/B^r instead of B_\phi -- well, can't divide by B^r
    //
    ////////
    if(VARTOINTERP==PRIMTOINTERP_GDETFULLVERSION_WALD && boundary==X1UP){ // WALD:
      int ddirl;
      for(pl=B1;pl<=B2;pl++){
        if(pl==B1) ddirl=1;
        if(pl==B2) ddirl=2;
        MACP0A1(prim,i,j,k,pl) =  (MACP0A1(prim,ri,rj,rk,pl)*sqrt(fabs(ptrrgeom[pl]->gcov[GIND(ddirl,ddirl)])) + 0.0*dqorthopl[pl]*(i-ri))/sqrt(fabs(ptrgeom[pl]->gcov[GIND(ddirl,ddirl)]));
                //        MACP0A1(prim,i,j,k,pl) =  (MACP0A1(prim,ri,rj,rk,pl)*sqrt(fabs(ptrrgeom[pl]->gcov[GIND(ddirl,ddirl)])) + dqorthopl[pl]*(i-ri))/sqrt(fabs(ptrgeom[pl]->gcov[GIND(ddirl,ddirl)]));
        //        MACP0A1(prim,i,j,k,pl) =  (MACP0A1(prim,ri,rj,rk,pl));

      }

    }
    else{
      for(pl=B1;pl<=B2;pl++){
        igdetnosing=sign(ptrgeom[pl]->gdet)/(fabs(ptrgeom[pl]->gdet)+SMALL); // avoids 0.0 for any sign of ptrgeom->gdet
        MACP0A1(prim,i,j,k,pl) =  (MACP0A1(prim,ri,rj,rk,pl)*(ptrrgeom[pl]->gdet) + dqgdetpl[pl]*(i-ri))*igdetnosing;
      }
    }



#define EXTRAPBD3 0

    if(EXTRAPBD3){
      ///////////////
      //
      // obtian generally correct B^\phi[B^r,B^\theta,B_\phi]
      //
      ///////////////
      if(dirprim[B3]==FACE3){
        // then assume staggered method
        // need to average fields
        //      Bu1=0.25*(MACP0A1(prim,i,j,k,B1)+MACP0A1(prim,ip1,j,k,B1)+MACP0A1(prim,i,j,km1,B1)+MACP0A1(prim,ip1,j,km1,B1));
        //Bu2=0.25*(MACP0A1(prim,i,j,k,B2)+MACP0A1(prim,i,jp1,k,B2)+MACP0A1(prim,i,j,km1,B2)+MACP0A1(prim,i,jp1,km1,B2));
        // assume average just results in the same value since can't average non-set values
        Bu1=MACP0A1(prim,i,j,k,B1);
        Bu2=MACP0A1(prim,i,j,k,B2);
      }
      else{
        // then assume all fields at CENT
        Bu1=MACP0A1(prim,i,j,k,B1);
        Bu2=MACP0A1(prim,i,j,k,B2);
      }
      gcon03=ptrgeom[B3]->gcon[GIND(0,3)];
      gcon13=ptrgeom[B3]->gcon[GIND(1,3)];
      gcon23=ptrgeom[B3]->gcon[GIND(2,3)];
      gcon33=ptrgeom[B3]->gcon[GIND(3,3)];

      gcov01=ptrgeom[B3]->gcov[GIND(0,1)];
      gcov02=ptrgeom[B3]->gcov[GIND(0,2)];
      gcov11=ptrgeom[B3]->gcov[GIND(1,1)];
      gcov12=gcov21=ptrgeom[B3]->gcov[GIND(1,2)];
      gcov22=ptrgeom[B3]->gcov[GIND(2,2)];
      gcov03=ptrgeom[B3]->gcov[GIND(0,3)];
      gcov13=ptrgeom[B3]->gcov[GIND(1,3)];
      gcov23=ptrgeom[B3]->gcov[GIND(2,3)];
   
      // Bd3fromBu.nb (just moved signs)
      myBd3=Bd3 + dqBd3*(i-ri);
      ftemp=(1.0 - gcon03*gcov03 - gcon13*gcov13 - gcon23*gcov23);
      igdetnosing=sign(ftemp)/(fabs(ftemp)+SMALL);
      pl=B3; MACP0A1(prim,i,j,k,pl) = (myBd3*gcon33 + Bu1*gcon03*gcov01 + Bu2*gcon03*gcov02 + Bu1*gcon13*gcov11 + Bu2*gcon13*gcov12 + Bu1*gcon23*gcov21 + Bu2*gcon23*gcov22)*igdetnosing;

      // old B_\phi imprecise copy (need to avoid singularity anywways)
      //   pl=B3; MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj,rk,pl)*((ptrrgeom[pl]->gcov[GIND(3,3)])/(ptrgeom[pl]->gcov[GIND(3,3)]));
    }
    else{
      // maybe more consistent with interpolation
      // also seems to be less large values in general near poles for tilted spins
      pl=B3;
      igdetnosing=sign(ptrgeom[pl]->gdet)/(fabs(ptrgeom[pl]->gdet)+SMALL); // avoids 0.0 for any sign of ptrgeom->gdet
      MACP0A1(prim,i,j,k,pl) =  (MACP0A1(prim,ri,rj,rk,pl)*(ptrrgeom[pl]->gdet) + dqgdetpl[pl]*(i-ri))*igdetnosing;
    }
    



  } // end LOOP over i and pl




  return(0);



}




#define UTHETAPOLEDEATH ((PRIMTOINTERP_3VELREL_GAMMAREL_DXDXP==VARTOINTERP)?(1):(0)) //only interpolate u^\theta instead of u^2 here when doing the same in interp

#if(0 == UTHETAPOLEDEATH)
#   define MACP0A1mod(prim,ri,rj,rk,pl) MACP0A1(prim,ri,rj,rk,pl)
#else
///average u^\theta=u^2*dxdxp22 as opposed to u^2
static FTYPE MACP0A1mod(FTYPE (*prim)[NSTORE2][NSTORE3][NPR], int ri, int rj, int rk, int pl);

static FTYPE MACP0A1mod(FTYPE (*prim)[NSTORE2][NSTORE3][NPR], int ri, int rj, int rk, int pl)
{
  FTYPE dxdxp[NDIM][NDIM];
  int dir;

#if(PRODUCTION==0)
  if ( dir < U2 || dir > B3 ) {
    dualfprintf( fail_file, "dir cannot be < U2 or > B3 in MACP0A1mod()\n" );
    exit(3232);
  }
#endif
    
  dir = 1 + (pl-U1)%3; //direction that corresponds to pl (e.g., 2 for U2 or B2); assumes contiguous ordering of pl: <..>,U1,U2,U3,B1,B2,B3,<..>
    
  dxdxprim_ijk(ri, rj, rk, CENT, dxdxp);
    
  return( MACP0A1(prim,ri,rj,rk,pl) * dxdxp[dir][dir] );   
}
#endif










/// interpolate across pole to remove numerical errors there
/// Note that this function is done over all zones
int poledeath(int whichx2,
              int boundstage, int finalstep, SFTYPE boundtime, int whichdir, int boundvartype, int *dirprim, int ispstag, FTYPE (*prim)[NSTORE2][NSTORE3][NPR],
              int *inboundloop,
              int *outboundloop,
              int *innormalloop,
              int *outnormalloop,
              int (*inoutlohi)[NUMUPDOWN][NDIM],
              int riin, int riout, int rjin, int rjout, int rkin, int rkout,
              int *dosetbc,
              int enerregion,
              int *localenerpos)
{




  // when poledeath() called, already in parallel region
  //#pragma omp parallel  // assume don't require EOS
  //  {

  int jj;
  int i,j,k;
  int pl,pliter;
  int rim1,rip1;
  int ri,rj,rk;
  int rj0;
  int rjstag;
  int rjtest,rjstag0,deathstagjs0,deathstagje0,rjstagtest,deathstagjstest,deathstagjetest;
  int poleloc;
  int poleloccent;
  int deathjs0,deathje0;
  int deathjs,deathje;
  int deathstagjs,deathstagje;
  int gammadeathjs,gammadeathje;
  FTYPE X[NPR][NDIM];
  FTYPE V[NPR][NDIM];
  FTYPE Xr[NPR][NDIM];
  FTYPE X0[NDIM];
  int lowrho,lowuu,highu1;
  int deathjstest,deathjetest;
  FTYPE gamma,gammarj0,gammarjtest;
  FTYPE qsq,qsqrj0,qsqrjtest;
  FTYPE ftemp;
  FTYPE ucon[NDIM];
  FTYPE others[NUMOTHERSTATERESULTS];
  FTYPE uconrad[NDIM];
  FTYPE othersrad[NUMOTHERSTATERESULTS];
  FTYPE gammavaluelimit,gammaradvaluelimit;
  int doavginradius[NPR];
  int pl2;
  struct of_geom geomdontuse[NPR];
  struct of_geom *ptrgeom[NPR];
  struct of_geom rgeomdontuse[NPR];
  struct of_geom *ptrrgeom[NPR];
  FTYPE dxdxp[NDIM][NDIM];
  FTYPE prdiag[NPR],pr[NPR];
  int jstep;
  struct of_geom geompoledontuse;
  struct of_geom *ptrgeompole=&geompoledontuse;


  // NOTE: If bounding less than full quantities, this won't be good diag quantity.
  int testplexist[MAXNPR]={0};
  int candodiag=1;
  PBOUNDLOOP(pliter,pl) testplexist[pl]=1;
  PLOOP(pliter,pl){ // yes, should be PLOOP(pliter,pl)
    if(testplexist[pl]!=1){
      candodiag=0;
    }
  }


  // OPENMPMARK: Can't do this check because if reduce to 1 thread (even in OpenMP) then omp_in_parallel() is false!
  //#if(USEOPENMP)
  //  // ensure within parallel region
  //  if(!omp_in_parallel()){
  //    dualfprintf(fail_file,"poledeath() called outside parallel region\n");
  //    myexit(84968346);
  //  }
  //#endif


  //////////////////
  //
  // assign memory
  //
  //////////////////
  PALLLOOP(pl){
    ptrgeom[pl]=&(geomdontuse[pl]);
    ptrrgeom[pl]=&(rgeomdontuse[pl]);
  }



  









  /////////////////////
  //
  // Loop over i,k
  //
  /////////////////////

  if(POLEDEATH){

    ///////    LOOPX2dir{
    OPENMPBCLOOPVARSDEFINELOOPX2DIR; OPENMPBCLOOPSETUPLOOPX2DIR;
#pragma omp for schedule(OPENMPSCHEDULE(),OPENMPCHUNKSIZE(blocksize))
    OPENMPBCLOOPBLOCK{
      OPENMPBCLOOPBLOCK2IJKLOOPX2DIR(i,k);



      //////////////////
      //
      // setup loop ranges
      //
      //////////////////

      int poledeathreal,polegammadeathreal;
      FTYPE Vtemp[NDIM];
      // note that doesn't matter the order of the j-loop since always using reference value (so for loop doesn't need change in <= to >=)
      if(whichx2==X2DN){

        //#define RADIUSOUTERDEATHMORE 300.0
#define RADIUSOUTERDEATHMORE (BIG) //(OUTERDEATHRADIUS) // i.e. inactive

        bl_coord_ijk(i,0,k,CENT,Vtemp);
        if(Vtemp[1]>RADIUSOUTERDEATHMORE){
          poledeathreal=N2BND;
          polegammadeathreal=N2BND;
        }
        else{
          poledeathreal=POLEDEATH;
          polegammadeathreal=POLEGAMMADEATH;
        }


        jstep=-1; // direction of j loop, so starts with active cells in case modify boundary cells as dependent upon active cells.

        rj0 = poledeathreal;
        rjtest = rj0+DEATHEXPANDAMOUNT; // used to ensure near pole the density doesn't drop suddenly
        poleloc = 0;
        poleloccent = 0;
        // for poledeathreal==2, then deathjs,je=-2,-1,0,1 as required for CENT quantities rj=2
        deathjs0 = 0-poledeathreal;
        deathje0 = 0+poledeathreal-1;

        deathjstest = deathjs0-DEATHEXPANDAMOUNT;
        deathjetest = deathje0+DEATHEXPANDAMOUNT;
        if(deathjstest<inoutlohi[POINTDOWN][POINTDOWN][2]) deathjstest=inoutlohi[POINTDOWN][POINTDOWN][2];
        if(deathjetest<inoutlohi[POINTDOWN][POINTDOWN][2]) deathjetest=inoutlohi[POINTDOWN][POINTDOWN][2];

        // assume for poledeathreal==1 that B2 set correctly as 0 on pole and only do something if poledeathreal>1
        // if poledeathreal==2 then B2 set at  -1,0,1 and will correctly set B2 to 0 at pole rj=2
        rjstag0 = rj0;
        deathstagjs0 = 0-poledeathreal+1;
        deathstagje0 = 0+poledeathreal-1;

        rjstagtest = rjtest;
        deathstagjstest = deathstagjs0-DEATHEXPANDAMOUNT;
        deathstagjetest = deathstagje0+DEATHEXPANDAMOUNT;
        if(deathstagjstest<inoutlohi[POINTDOWN][POINTDOWN][2]) deathstagjstest=inoutlohi[POINTDOWN][POINTDOWN][2];
        if(deathstagjetest<inoutlohi[POINTDOWN][POINTDOWN][2]) deathstagjetest=inoutlohi[POINTDOWN][POINTDOWN][2];

        // assumes velocity is always CENT
        gammadeathjs=0-polegammadeathreal;
        gammadeathje=0+polegammadeathreal-1;
        if(gammadeathjs<inoutlohi[POINTDOWN][POINTDOWN][2]) gammadeathjs=inoutlohi[POINTDOWN][POINTDOWN][2];
        if(gammadeathje<inoutlohi[POINTDOWN][POINTDOWN][2]) gammadeathje=inoutlohi[POINTDOWN][POINTDOWN][2];

        // NO, don't do below.  Since poledeath called after MPI, need to set ghost cells as consistent with how active cells would have been set by other part of grid or other CPUs
        //    if(special3dspc){
        //      // then assume poledeath called *after* MPI (so have full and correct information across pole), so only should modify active cells and not boundary cells
        //      deathjs0 = 0;
        //      deathjstest = 0;
        //      deathstagjs0 = 0;
        //      deathstagjstest = 0;
        //      gammadeathjs=0;
        //    }

      }
      else if(whichx2==X2UP){

        bl_coord_ijk(i,N2BND,k,CENT,Vtemp);
        if(Vtemp[1]>RADIUSOUTERDEATHMORE){
          poledeathreal=N2BND;
          polegammadeathreal=N2BND;
        }
        else{
          poledeathreal=POLEDEATH;
          polegammadeathreal=POLEGAMMADEATH;
        }

        rj0=N2-1-poledeathreal;
        rjtest = rj0-DEATHEXPANDAMOUNT;
        poleloc=N2;
        poleloccent=N2-1;
        // if poledeathreal==2 then CENTs set at N2-2,N2-1,N2,N2+1 rj=N2-3
        deathjs0 = N2-1+1-poledeathreal;
        deathje0 = N2-1+poledeathreal;

        deathjstest = deathjs0-DEATHEXPANDAMOUNT;
        deathjetest = deathje0+DEATHEXPANDAMOUNT;
        if(deathjstest>inoutlohi[POINTUP][POINTUP][2]) deathjstest=inoutlohi[POINTUP][POINTUP][2];
        if(deathjetest>inoutlohi[POINTUP][POINTUP][2]) deathjetest=inoutlohi[POINTUP][POINTUP][2];

        // if poledeathreal==2, then B2 is set at N2-1,N2,N2+1 rj=N2-3
        if(dirprim[B2]==FACE2) rjstag0=N2-poledeathreal;
        else if(dirprim[B2]==CENT) rjstag0=rj0;
        deathstagjs0 = N2+1-poledeathreal;
        deathstagje0 = N2-1+poledeathreal;

        rjstagtest = rjtest;
        deathstagjstest = deathstagjs0-DEATHEXPANDAMOUNT;
        deathstagjetest = deathstagje0+DEATHEXPANDAMOUNT;
        if(deathstagjstest>inoutlohi[POINTUP][POINTUP][2]) deathstagjstest=inoutlohi[POINTUP][POINTUP][2];
        if(deathstagjetest>inoutlohi[POINTUP][POINTUP][2]) deathstagjetest=inoutlohi[POINTUP][POINTUP][2];


        // assumes velocity is always CENT .  If POLEDEATH==2, N2-2,N2-1,N2,N2+1
        gammadeathjs = N2-1+1-polegammadeathreal;
        gammadeathje = N2-1+polegammadeathreal;
        if(gammadeathjs>inoutlohi[POINTUP][POINTUP][2]) gammadeathjs=inoutlohi[POINTUP][POINTUP][2];
        if(gammadeathje>inoutlohi[POINTUP][POINTUP][2]) gammadeathje=inoutlohi[POINTUP][POINTUP][2];


        //    if(special3dspc){
        //      // then assume poledeath called *after* MPI (so have full and correct information across pole), so only should modify active cells and not boundary cells
        //      deathje0 = N2-1;
        //      deathjetest = N2-1;
        //      deathstagje0 = N2-1;
        //      deathstagjetest = N2-1;
        //      gammadeathje=N2-1;
        //    }

      }

      if(LIMITEDPOLEDEATHINRADIUS){
        FTYPE Rhorref=rhor_calc(0);
        if(ispstag==0){
          // even problems with poledeath for within horizon, can lead to Erf blowing up, so why 1|| below
          if(  (1||startpos[1]+i>N1BND || Vtemp[1]>0.9*Rhorref) && (Vtemp[1]<OUTERDEATHRADIUS && OUTERDEATH==1 || OUTERDEATH==0)) continue;
        }
      }

      //////////////
      //
      // Skip this i,k if doing limited poledeath()
      //
      //////////////

      int dontskippoledeath;
      dontskippoledeath=0;
      if(IFLIMITPOLEDEATHIOUT>0){
        if(mycpupos[1]==ncpux1-1){
          if(i>N1-1-IFLIMITPOLEDEATHIOUT){
            // then force use of poledeath (no skip allowed)
            dontskippoledeath=1;
            //dualfprintf(fail_file,"OUTERDONTSKIP: %d %d %d\n",i,j,k);
          }
        }
      }
      

      if(IFLIMITPOLEDEATH>0 && ispstag==0 && dontskippoledeath==0){ // only go here if still possible to skip poledeath
        // assume only can skip if centered primitives (staggered are field, and nominally don't change them)

        FTYPE Vpole[NDIM];
 
        // use centered cell value (i.e. pl=RHO) to determine radius, and skip rest of this "j" if radius outside
        bl_coord_ijk(i,poleloc,k,FACE2,Vpole); // FACE2 at CENT for radius, but using FACE2 allows us to use j=poleloc

        // get u^\mu
        j=poleloccent;
        get_geometry(i, j, k, CENT, ptrgeompole);
        ucon_calc(MAC(prim,i,j,k),ptrgeompole,ucon, others);


        if(IFLIMITPOLEDEATH==1){
          if(ucon[RR]>=0.0){
            //dualfprintf(fail_file,"SKIP1: %d %d %d : %g %g\n",i,j,k,ucon[RR],Vpole[1]);
            continue;
          }
        }
        else if(IFLIMITPOLEDEATH==2){
          if(Vpole[1]>=RADIUSLIMITPOLEDEATHIN){
            //dualfprintf(fail_file,"SKIP2: %d %d %d : %g %g\n",i,j,k,ucon[RR],Vpole[1]);
            continue;
          }
        }
        else if(IFLIMITPOLEDEATH==3){
          if(ucon[RR]>=0.0 && Vpole[1]>=RADIUSLIMITPOLEDEATHIN){ // i.e., do poledeath unless *both* u^r>0 *and* beyond given radius
            //dualfprintf(fail_file,"SKIP3: %d %d %d : %g %g\n",i,j,k,ucon[RR],Vpole[1]);
            continue;
          }
        }


        //dualfprintf(fail_file,"NOTSKIP: %d %d %d : %g %g\n",i,j,k,ucon[RR],Vpole[1]);
 
      }





      // set reference positions in i,k
      ri = i;
      rk = k;


      //////////////////
      //
      // set radial positions to average over
      //
      //////////////////
      if(ri==inoutlohi[POINTDOWN][POINTDOWN][1]){
        // shift up, but not including ri
        rim1=ri+1;
        rip1=ri+2;
      }
      else if(ri==inoutlohi[POINTUP][POINTUP][1]){
        // shift down, but not including ri
        rim1=ri-2;
        rip1=ri-1;
      }
      else{
        // around ri
        rim1=ri-1;
        rip1=ri+1;
      }
    




      /////////////
      // first check for significant density drops near the axis or Lorentz factor spikes up near axis
      lowrho=lowuu=0;
      highu1=0;


      if(0){ // disabled for now

        get_geometry(ri, rj0, rk, dirprim[U1], ptrrgeom[U1]);
        gamma_calc(MAC(prim,ri,rj0,rk), ptrrgeom[U1],&gammarj0,&qsqrj0);
    
        get_geometry(ri, rjtest, rk, dirprim[U1], ptrrgeom[U1]);
        gamma_calc(MAC(prim,ri,rjtest,rk), ptrrgeom[U1],&gammarjtest,&qsqrjtest);



        for (j = deathjs0; j <= deathje0; j++) { // (no prims modified here, so no need for special j loop or diag_fixup)

          //POLEDENSITYDROPFACTOR
          //POLEGAMMAJUMPFACTOR


          pl=RHO;
          if(fabs(MACP0A1(prim,i,j,k,pl))< fabs(MACP0A1(prim,ri,rj0,rk,pl))/POLEDENSITYDROPFACTOR || fabs(MACP0A1(prim,i,j,k,pl))< fabs(MACP0A1(prim,ri,rjtest,rk,pl))/POLEDENSITYDROPFACTOR){
            lowrho=1;
          }
          pl=UU;
          if(fabs(MACP0A1(prim,i,j,k,pl))< fabs(MACP0A1(prim,ri,rj0,rk,pl)/POLEDENSITYDROPFACTOR) || fabs(MACP0A1(prim,i,j,k,pl))< fabs(MACP0A1(prim,ri,rjtest,rk,pl))/POLEDENSITYDROPFACTOR){
            lowuu=1;
          }


          // get Lorentz factor
          get_geometry(i, j, k, dirprim[U1], ptrrgeom[U1]);
          gamma_calc(MAC(prim,i,j,k), ptrrgeom[U1],&gamma,&qsq);


          //      pl=U1;
          //      if(fabs(MACP0A1(prim,i,j,k,pl))> fabs(MACP0A1(prim,ri,rj0,rk,pl))/POLEJUMPFACTOR || fabs(MACP0A1(prim,i,j,k,pl))> fabs(MACP0A1(prim,ri,rjtest,rk,pl))/POLEJUMPFACTOR ){
          // highu1=1;
          //      }

          // check variation of Lorentz factor
          if(gamma> gammarj0*POLEGAMMAJUMPFACTOR || gamma> gammarjtest*POLEGAMMAJUMPFACTOR ){
            highu1=1;
          }


        }
    
        if(lowuu || lowrho || highu1){
          rj=rjtest; // expand copy procedure to use better reference value
          deathjs=deathjstest;
          deathje=deathjetest;

          rjstag=rjstagtest; // expand copy procedure to use better reference value
          deathstagjs=deathstagjstest;
          deathstagje=deathstagjetest;
        }
        else{
          // then use normal reference and range
          rj=rj0;
          deathjs=deathjs0;
          deathje=deathje0;

          rjstag=rjstag0;
          deathstagjs=deathstagjs0;
          deathstagje=deathstagje0;
        }
      }
      else{
        rj=rjtest; // expand copy procedure to use better reference value
        deathjs=deathjstest;
        deathje=deathjetest;
      
        rjstag=rjstagtest; // expand copy procedure to use better reference value
        deathstagjs=deathstagjstest;
        deathstagje=deathstagjetest;
      }




      ////////////////////////////////
      //
      // reference location geometry and coordinates
      //
      ////////////////////////////////

      PBOUNDLOOP(pliter,pl) {
        coord_ijk(ri,rj,rk,dirprim[pl],Xr[pl]); // reference locations for B2/U2
        if(pl==B2 && dirprim[B2]==FACE2){
          get_geometry(ri, rjstag, rk, dirprim[pl], ptrrgeom[pl]);
        }
        else{
          get_geometry(ri, rj, rk, dirprim[pl], ptrrgeom[pl]);
        }
      }






      //#define DEATHLOOP2 for (j = MIN(deathstagjs,deathjs); j <= MAX(deathstagje,deathje); j++) {
      //      for (j = MIN(deathstagjs,deathjs); j <= MAX(deathstagje,deathje); j++) {
      // always iterate from active to ghost cell, so can modify active and have ready for ghost
      // didn't redefine js and je, they always go from small to large values, which is why ordering below
#define DEATHLOOP2(whichx2) for (j = (whichx2==X2UP ? MIN(deathstagjs,deathjs) : MAX(deathstagje,deathje)) ; (whichx2==X2UP ? (j <= MAX(deathstagje,deathje)) : (j >= MIN(deathstagjs,deathjs)) )   ; (whichx2==X2UP ? j++ : j--) )

      ////////////////////////////////
      //
      // For RHO,UU,U1,U3,B(1,2,3), and other primitives assumed to be like density
      //
      // Loop over points to be modified (prim's are only modifed HERE!)
      //
      ////////////////////////////////

      DEATHLOOP2(whichx2){



        //////////////
        //
        // setup initial pr
        //
        //////////////
        // 
        PBOUNDLOOP(pliter,pl) prdiag[pl]=MACP0A1(prim,i,j,k,pl);
        int madechange=0;




        PBOUNDLOOP(pliter,pl) {
          // pole location
          coord_ijk(i,poleloc,k,FACE2,X0); // pole locations for B2/U2

          // current location
          bl_coord_ijk_2(i,j,k,dirprim[pl],X[pl],V[pl]);
          get_geometry(i, j, k, dirprim[pl], ptrgeom[pl]);

          if(AVERAGEINRADIUS && (V[pl][RR]>RADIUSTOSTARTAVERAGING)){
            doavginradius[pl]=1;
          }
          else doavginradius[pl]=0;

        }// end pboundloop




        /////////////
        //
        // velocity and DENSITY (rho,u) POLEDATH
        //
        /////////////
        if(ispstag==0){
          // symmetric (if reflecting BC at pole) quantities
          if(j>=deathjs && j<=deathje){


            //////////
            // u1, and u3, average in radius too!
            // copying this means copying \Omega_F in magnetically-dominated regime beyond LC
            PBOUNDLOOP(pliter,pl) {
              if(!(pl==U1 || pl==U3 || pl==URAD1 || pl==URAD3)) continue;
  
              FTYPE myvalue;
              myvalue=MACP0A1(prim,i,j,k,pl);
              FTYPE avgresult;
              if(doavginradius[pl]){
                avgresult=THIRD*(MACP0A1(prim,rim1,rj,rk,pl)+MACP0A1(prim,ri,rj,rk,pl)+MACP0A1(prim,rip1,rj,rk,pl));
              }
              else{
                avgresult=MACP0A1(prim,ri,rj,rk,pl);
              }

              if(1||fabs(avgresult)<myvalue){// only use reference if smaller value of velocity // well, for now, just copy over velocity under no additional conditions
                MACP0A1(prim,i,j,k,pl) = avgresult;
                madechange++;
              }
            }



            if(EOMTYPE!=EOMFFDE && EOMTYPE!=EOMFFDE2){
              //////////
              // for densities
              // this helps remove drop-outs in density at high b^2/\rho_0 and high b^2/u
              PBOUNDLOOP(pliter,pl) {
                if(!(pl==RHO || pl==UU || pl==ENTROPY || pl==URAD0)) continue;

                FTYPE myvalue;
                myvalue=MACP0A1(prim,i,j,k,pl);
                FTYPE avgresult;
                if(doavginradius[pl]){
                  avgresult=THIRD*(MACP0A1(prim,rim1,rj,rk,pl)+MACP0A1(prim,ri,rj,rk,pl)+MACP0A1(prim,rip1,rj,rk,pl));
                }
                else{
                  avgresult=MACP0A1(prim,ri,rj,rk,pl);
                }
                
                if(1||fabs(avgresult)>myvalue){// only use reference if it is larger than polar value.  That is, trying to avoid evacuation, and using smaller value of density only makes things worse, not better.
                  MACP0A1(prim,i,j,k,pl) = avgresult;
                  madechange++;
                }
  
              //                if(doavginradius[pl]) MACP0A1(prim,i,j,k,pl) = THIRD*(MACP0A1(prim,rim1,rj,rk,pl)+MACP0A1(prim,ri,rj,rk,pl)+MACP0A1(prim,rip1,rj,rk,pl));
              //                else MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,ri,rj,rk,pl);
              //                madechange++;
              }


              if(BCSIGMACONSTATPOLE==1){
  
                pl=RHO;
                FTYPE bsqr,sigmar;
  
                if (bsq_calc(MAC(prim,ri,rj,rk), ptrrgeom[pl], &bsqr) >= 1) FAILSTATEMENT("bounds.tools.c:poledeath()", "bsq_calc()", 1);
                sigmar=bsqr/(2.0*fabs(MACP0A1(prim,ri,rj,rk,pl)));
  
                // ensure constant sigma at pole
                FTYPE bsq,sigma;
                if (bsq_calc(MAC(prim,i,j,k), ptrgeom[pl], &bsq) >= 1) FAILSTATEMENT("bounds.tools.c:poledeath()", "bsq_calc()", 2);
                sigma=bsq/(2.0*fabs(MACP0A1(prim,i,j,k,pl)));
  
                if(sigma>BSQORHOLIMIT*0.5 && sigmar<BSQORHOLIMIT*0.5){
                  MACP0A1(prim,i,j,k,pl) = fabs(MACP0A1(prim,i,j,k,pl)*(sigma/sigmar));
                  madechange++;
                }
                // do nothing different than simple copy in any other cases.  NOTE: If not high sigma, else if near-pole is low sigma, then this feeds in mass crazily
              }// end if BCSIGMACONSTATPOLE==1
            }// end if EOMTYPE!=EOMFFDE && EOMTYPE!=EOMFFDE2


          }// end if correct j
        }// end if ispstag==0




        //////////////
        //
        // symmetric (if reflecting BC at pole) quantities (e.g. B1)
        //
        //////////////
        if(j>=deathjs && j<=deathje){
          // B1 left alone
        }



        /////////////
        //
        // antisymmetric quantities (e.g. B2)
        //
        /////////////
        if(
           dirprim[B2]==FACE2 && j>=deathstagjs && j<=deathstagje || 
           dirprim[B2]==CENT && j>=deathjs && j<=deathje
           ){
   
          if(N2==1){
            /////////////////////////////
            // B2:
#if(POLEINTERPTYPE==0)
            // if flow converges toward pole, then this loses information about the velocity and field approaching the pole
            // anti-symmetric (if reflecting BC at pole) quantities:
            MACP0A1(prim,i,j,k,B2) = 0.;
            madechange++;

#elif(POLEINTERPTYPE==1 || POLEINTERPTYPE==2)
            // anti-symmetric (if reflecting BC at pole):
            // assume X[2] goes through 0 at the pole and isn't positive definite
            pl=B2;
            if(doavginradius[pl]) ftemp=THIRD*(MACP0A1(prim,rim1,rjstag,rk,pl) + MACP0A1(prim,ri,rjstag,rk,pl) + MACP0A1(prim,rip1,rjstag,rk,pl));
            else  ftemp=MACP0A1(prim,ri,rjstag,rk,pl);
            MACP0A1(prim,i,j,k,pl) = ftemp + (X[pl][2]-Xr[pl][2])*(ftemp-0.0)/(Xr[pl][2]-X0[2]);
            madechange++;

#elif(POLEINTERPTYPE==3)
            // then don't modify B2 -- trying to avoid instabilities related to divb=0 violation.  And seems B2 behaves ok
#endif
          }
          else{
            // then don't modify B2 to ensure divB=0
          }

        }





        /////////////
        //
        // other symmetric quantities (e.g. B3)
        //
        /////////////
        if(j>=deathjs && j<=deathje){

          ////////////////
          // B3:
          pl=B3;

          if(N3==1){

#if(POLEINTERPTYPE==0 || POLEINTERPTYPE==1)
            // symmetric:
            if(doavginradius[pl]) ftemp=THIRD*(MACP0A1(prim,rim1,rj,rk,pl) + MACP0A1(prim,ri,rj,rk,pl) + MACP0A1(prim,rip1,rj,rk,pl));
            else ftemp=MACP0A1(prim,ri,rj,rk,pl);
            MACP0A1(prim,i,j,k,B3) = ftemp;
            madechange++;

#elif(POLEINTERPTYPE==2)
            // symmetric:
            // approximate B_\phi copy, which (unlike copying B3) can resolve singular currents on axis
            if(doavginradius[pl]) ftemp=THIRD*(MACP0A1(prim,rim1,rj,rk,pl) + MACP0A1(prim,ri,rj,rk,pl) + MACP0A1(prim,rip1,rj,rk,pl));
            else ftemp=MACP0A1(prim,ri,rj,rk,pl);
            MACP0A1(prim,i,j,k,pl) =  ftemp*fabs((ptrrgeom[pl]->gcov[GIND(3,3)])/(ptrgeom[pl]->gcov[GIND(3,3)]));
            madechange++;

#elif(POLEINTERPTYPE==3)
            // symmetric:
            if(doavginradius[pl]) ftemp=THIRD*(MACP0A1(prim,rim1,rj,rk,pl) + MACP0A1(prim,ri,rj,rk,pl) + MACP0A1(prim,rip1,rj,rk,pl));
            else ftemp=MACP0A1(prim,ri,rj,rk,pl);
            MACP0A1(prim,i,j,k,B3) = ftemp;
            madechange++;
#endif
          }// end if N3==1
          else{
            // then do nothing if in 3D
          }




          ///////////////////////////////////
          //
          // do rest if any -- assumed at CENT
          //
          ///////////////////////////////////
          if(ispstag==0){
            PBOUNDLOOP(pliter,pl){
              if((pl==RHO || pl==UU || pl==U1 || pl==U2 || pl==U3 || pl==ENTROPY || pl==B1 || pl==B2 || pl==B3 || pl==URAD0 || pl==URAD1 || pl==URAD2 || pl==URAD3)) continue;

              if(doavginradius[pl]) ftemp=THIRD*(MACP0A1(prim,rim1,rj,rk,pl) + MACP0A1(prim,ri,rj,rk,pl) + MACP0A1(prim,rip1,rj,rk,pl));
              else ftemp=MACP0A1(prim,ri,rj,rk,pl);
              MACP0A1(prim,i,j,k,pl)=ftemp;
              madechange++;
            }
          }

        }// end over CENT-type quantities



        if(madechange && candodiag){
          ///////////
          //
          // accounting for on-grid changes
          //
          ////////////
          int modcons=(DOENOFLUX != NOENOFLUX);
          FTYPE *ucons;
          ucons=GLOBALMAC(unewglobal,i,j,k); // GODMARK -- need to pass ucons to bounds if really want !=NOENOFLUX method to work
          // GODMARK: assume all quantities at the same location since only ispstag==0 modifies relevant primitves, so ptrgeom[pl]->ptrgoem
          // in general, not sure which pl really exists at this point, so pick first in PBOUNDLOOP loop
          struct of_geom *fixupptrgeom;
          PBOUNDLOOP(pliter,pl) {
            fixupptrgeom=ptrgeom[pl];
            break;
          }
          PBOUNDLOOP(pliter,pl) pr[pl]=MACP0A1(prim,i,j,k,pl);
          int doingmhdfixup=1;
          diag_fixup(modcons,prdiag,pr,ucons,fixupptrgeom,finalstep,doingmhdfixup,COUNTBOUND1);
          PBOUNDLOOP(pliter,pl) prdiag[pl]=pr[pl];
        }

      
      }// end loop over j






      ////////////////////////////////
      //
      // FOR U2 alone!
      //
      // Loop over points to be modified (prim's are only modifed HERE!)
      //
      // independent loop over j from above density loop because U2 changes may required RHO and those must already all be changed for all j
      //
      ////////////////////////////////

      DEATHLOOP2(whichx2){



        //////////////
        //
        // setup initial pr
        //
        //////////////
        PBOUNDLOOP(pliter,pl) prdiag[pl]=MACP0A1(prim,i,j,k,pl);
        int madechange=0;




        PBOUNDLOOP(pliter,pl) {
          // pole location
          coord_ijk(i,poleloc,k,FACE2,X0); // pole locations for B2/U2

          // current location
          bl_coord_ijk_2(i,j,k,dirprim[pl],X[pl],V[pl]);
          get_geometry(i, j, k, dirprim[pl], ptrgeom[pl]);

          if(AVERAGEINRADIUS && (V[pl][RR]>RADIUSTOSTARTAVERAGING)){
            doavginradius[pl]=1;
          }
          else doavginradius[pl]=0;

        }

      
      
        if(ispstag==0){
 
          if(j>=deathjs && j<=deathje){
            //////////////////////////
            int iteru2;
            int plrho;
            for(iteru2=0;iteru2<=1;iteru2++){
              // U2:
              if(iteru2==0){
                pl=U2;
                plrho=RHO;
              }
              else if(iteru2==1){
                pl=URAD2;
                plrho=URAD0;
              }
              if(URAD0<0) continue; // skip of not doing radiation
              


              if(special3dspc){
                // U2 not necessarily anti-symmetric in this case.
                // This will be kinda odd if POLEDEATH>1 due to comparing non-local regions.
                // But, for now, POLEDEATH<=1 is set so make sense.

                int jother;
                FTYPE signD;
                if(j<N2/2){
                  jother=-1-j;
                }
                else{
                  jother=N2-1+(N2-j);
                }

                if(j>=jother) signD=+1.0;
                else signD=-1.0;


                // see if sucking on pole
                FTYPE rhovjhere,rhovjother,rhovDiff;
                rhovjhere =MACP0A1(prim,i,j,k,plrho)*MACP0A1mod(prim,i,j,k,pl);
                rhovjother=MACP0A1(prim,i,jother,k,plrho)*MACP0A1mod(prim,i,jother,k,pl);

                rhovDiff=signD*(rhovjhere-rhovjother);
                // same gdet, so no need to multiply both by same factor for below test
                // make change to both simultaneously so that when other j is hit, rhovDiff condition is no longer hit and all is consistent as if separate memory field for entire poledeath before final copy-over to primitive memory space.
                // But do active grid cells first (determined by DEATHLOOPJ) so diag_fixup() occurs on active region for accounting.
                if(rhovDiff>0.0){
                  // then sucking on pole
                  // must change active and ghost cells consistently for any number of CPUs
                  // so average-out the suck to zero suck by changing the values equally (as weighted by mass)
                  FTYPE dU2     =-signD*rhovDiff*0.5/MACP0A1(prim,i,j,k,plrho);
                  FTYPE U2jhere = MACP0A1mod(prim,i,j,k,pl);
                  FTYPE U2jother= MACP0A1mod(prim,i,jother,k,pl);

                  if( (fabs(U2jhere)>fabs(dU2))&&(fabs(U2jother)>fabs(dU2)) ){
                    // only change if in both cases we lower the velocity, not increase.
                    MACP0A1(prim,i,j,k,pl)      += dU2;
                    MACP0A1(prim,i,jother,k,pl) -= dU2;
                    madechange++;
                  }
                  else{ // then jhere or jother is changed by an absolute magnitude more than its value, which we want to avoid
                    // crush a bit only as much as leaves smaller value changed as much as possible without increasing its magnitude
                    if(fabs(U2jhere)<fabs(U2jother)){
                      // then drop jhere as closest to fixed value (100% change), and reset jother with same value
                      MACP0A1(prim,i,j,k,pl) *= -1.0;
                      MACP0A1(prim,i,jother,k,pl) = MACP0A1(prim,i,j,k,pl);
                      madechange++;
                    }
                    else{
                      // then drops down to value matching other side so D=0 in the end still, so still no sucking.
                      MACP0A1(prim,i,jother,k,pl) *= -1.0;
                      MACP0A1(prim,i,j,k,pl) = MACP0A1(prim,i,jother,k,pl);
                      madechange++;
                    }
                  }// end else abs mag of change is larger than 100% for one of the values

                  //    MACP0A1(prim,i,j,k,pl)      =0.0;
                  //    madechange++;
                  //  MACP0A1(prim,i,jother,k,pl) += +rhovDiff*0.5/MACP0A1(prim,i,jother,k,plrho); // this taken care of by other j in ghost region

                  // Note that for anti-symmetric U2 (i.e. reflective BCs around pole) this is same as crushing regularization leading to pl->0
                }
                else{
                  // then just enforce linear behavior near pole
                  // NOT YET
                }


              }
              else{


#if(POLEINTERPTYPE==0)
                // if flow converges toward pole, then this loses information about the velocity and field approaching the pole
                // anti-symmetric (if reflecting BC at pole) quantities:
                MACP0A1(prim,i,j,k,pl) = 0.;
                madechange++;

#elif(POLEINTERPTYPE==1 || POLEINTERPTYPE==2)
                // anti-symmetric (if reflecting BC at pole):
                // assume X[2] goes through 0 at the pole and isn't positive definite
                if(doavginradius[pl]) ftemp=THIRD*(MACP0A1mod(prim,rim1,rj,rk,pl) + MACP0A1mod(prim,ri,rj,rk,pl) + MACP0A1mod(prim,rip1,rj,rk,pl));
                else ftemp=MACP0A1mod(prim,ri,rj,rk,pl);
                MACP0A1(prim,i,j,k,pl) = ftemp + (X[pl][2]-Xr[pl][2])*(ftemp-0.0)/(Xr[pl][2]-X0[2]);
                madechange++;

#elif(POLEINTERPTYPE==3)

                // anti-symmetric (if reflecting BC at pole):

                // assume X[2] goes through 0 at the pole and isn't positive definite

                // choose reference value
                //  ftemp=THIRD*(MACP0A1mod(prim,rim1,rj,rk,pl) + MACP0A1mod(prim,ri,rj,rk,pl) + MACP0A1mod(prim,rip1,rj,rk,pl));
                ftemp=MACP0A1mod(prim,ri,rj,rk,pl);

                if(whichx2==X2DN && ftemp>0.0){
                  // then sucking on \theta=0 pole
                  // try to minimize sucking on pole by finding minimum U2 around
                  for(jj=0;jj<=rj+DEATHEXPANDAMOUNT;jj++) ftemp=MIN(ftemp,MACP0A1mod(prim,ri,jj,rk,pl));
                  if(doavginradius[pl]){
                    for(jj=0;jj<=rj+DEATHEXPANDAMOUNT;jj++) ftemp=MIN(ftemp,MACP0A1mod(prim,rip1,jj,rk,pl));
                    for(jj=0;jj<=rj+DEATHEXPANDAMOUNT;jj++) ftemp=MIN(ftemp,MACP0A1mod(prim,rim1,jj,rk,pl));
                  }

                  ftemp=0.0; // try crushing sucking GODMARK

                  // assume ftemp is at reference location
                  MACP0A1(prim,i,j,k,pl) = ftemp + (X[pl][2]-Xr[pl][2])*(ftemp-0.0)/(Xr[pl][2]-X0[2]);
                  madechange++;
                }
                else if(whichx2==X2UP && ftemp<0.0){
                  // then sucking on \theta=\pi pole
                  for(jj=N2-1;jj>=rj-DEATHEXPANDAMOUNT;jj--) ftemp=MAX(ftemp,MACP0A1mod(prim,ri,jj,rk,pl));
                  if(doavginradius[pl]){
                    for(jj=N2-1;jj>=rj-DEATHEXPANDAMOUNT;jj--) ftemp=MAX(ftemp,MACP0A1mod(prim,rip1,jj,rk,pl));
                    for(jj=N2-1;jj>=rj-DEATHEXPANDAMOUNT;jj--) ftemp=MAX(ftemp,MACP0A1mod(prim,rim1,jj,rk,pl));
                  }

                  ftemp=0.0; // try crushing sucking GODMARK

                  // assume ftemp is at reference location (same formula for both poles)
                  MACP0A1(prim,i,j,k,pl) = ftemp + (X[pl][2]-Xr[pl][2])*(ftemp-0.0)/(Xr[pl][2]-X0[2]);
                  madechange++;
                }
                else{
                  // otherwise enforce natural regular linear behavior on U2
                  if(doavginradius[pl]) ftemp=THIRD*(MACP0A1mod(prim,rim1,rj,rk,pl) + MACP0A1mod(prim,ri,rj,rk,pl) + MACP0A1mod(prim,rip1,rj,rk,pl));
                  else ftemp=MACP0A1mod(prim,ri,rj,rk,pl);

                  MACP0A1(prim,i,j,k,pl) = ftemp + (X[pl][2]-Xr[pl][2])*(ftemp-0.0)/(Xr[pl][2]-X0[2]);
                  madechange++;
                }

#endif // endif POLEINTERPTYPE==3
              }// end if special3dspc==0


#if( UTHETAPOLEDEATH )
              if(pl==U2){
                //if interpolated u^\theta, now convert back to u^2
                dxdxprim_ijk(i, j, k, CENT, dxdxp);
                MACP0A1(prim,i,j,k,pl) /= dxdxp[1 + (pl-U1)%3][1 + (pl-U1)%3];
                madechange++;
              }
              if(pl==URAD2){
                //if interpolated u^\theta, now convert back to u^2
                dxdxprim_ijk(i, j, k, CENT, dxdxp);
                MACP0A1(prim,i,j,k,pl) /= dxdxp[1 + (pl-URAD1)%3][1 + (pl-URAD1)%3];
                madechange++;
              }
#endif

            }// over U2 and URAD2
          }// end if correct j range
        }// end if ispstag==0



        if(madechange&&candodiag){ // only need accounting if actually made a change
          ///////////
          //
          // accounting for on-grid changes
          //
          ////////////
          int modcons=(DOENOFLUX != NOENOFLUX);
          FTYPE *ucons;
          ucons=GLOBALMAC(unewglobal,i,j,k); // GODMARK -- need to pass ucons to bounds if really want !=NOENOFLUX method to work
          // GODMARK: assume all quantities at the same location since only ispstag==0 modifies relevant primitves, so ptrgeom[pl]->ptrgoem
          // in general, not sure which pl really exists at this point, so pick first in PBOUNDLOOP loop
          struct of_geom *fixupptrgeom;
          PBOUNDLOOP(pliter,pl) {
            fixupptrgeom=ptrgeom[pl];
            break;
          }

          PBOUNDLOOP(pliter,pl) pr[pl]=MACP0A1(prim,i,j,k,pl);
          int doingmhdfixup=1;
          diag_fixup(modcons,prdiag,pr,ucons,fixupptrgeom,finalstep,doingmhdfixup,COUNTBOUND1);
          PBOUNDLOOP(pliter,pl) prdiag[pl]=pr[pl];
        }


      }// end loop over j
    }// end loop 13
  }// end if POLEDEATH









  if(POLEGAMMADEATH){ // should come after POLEDEATH to be useful
    if(ispstag==0){
      // fixup


      // assume only dealing with velocities at same location (loop assumes CENT)
      pl=U1;


      ///////    LOOPX2dir{
      OPENMPBCLOOPVARSDEFINELOOPX2DIR; OPENMPBCLOOPSETUPLOOPX2DIR;
#pragma omp for schedule(OPENMPSCHEDULE(),OPENMPCHUNKSIZE(blocksize))
      OPENMPBCLOOPBLOCK{
        OPENMPBCLOOPBLOCK2IJKLOOPX2DIR(i,k);


        //////////////////
        //
        // setup loop ranges
        //
        //////////////////


        //////////////////////////////////////
        // BELOW JUST COPY OF ABOVE
        int poledeathreal,polegammadeathreal;
        FTYPE Vtemp[NDIM];
        // note that doesn't matter the order of the j-loop since always using reference value (so for loop doesn't need change in <= to >=)
        if(whichx2==X2DN){

          bl_coord_ijk(i,0,k,CENT,Vtemp);
          if(Vtemp[1]>RADIUSOUTERDEATHMORE){
            poledeathreal=N2BND;
            polegammadeathreal=N2BND;
          }
          else{
            poledeathreal=POLEDEATH;
            polegammadeathreal=POLEGAMMADEATH;
          }


          jstep=-1; // direction of j loop, so starts with active cells in case modify boundary cells as dependent upon active cells.

          rj0 = poledeathreal;
          rjtest = rj0+DEATHEXPANDAMOUNT; // used to ensure near pole the density doesn't drop suddenly
          poleloc = 0;
          poleloccent = 0;
          // for poledeathreal==2, then deathjs,je=-2,-1,0,1 as required for CENT quantities rj=2
          deathjs0 = 0-poledeathreal;
          deathje0 = 0+poledeathreal-1;

          deathjstest = deathjs0-DEATHEXPANDAMOUNT;
          deathjetest = deathje0+DEATHEXPANDAMOUNT;
          if(deathjstest<inoutlohi[POINTDOWN][POINTDOWN][2]) deathjstest=inoutlohi[POINTDOWN][POINTDOWN][2];
          if(deathjetest<inoutlohi[POINTDOWN][POINTDOWN][2]) deathjetest=inoutlohi[POINTDOWN][POINTDOWN][2];

          // assume for poledeathreal==1 that B2 set correctly as 0 on pole and only do something if poledeathreal>1
          // if poledeathreal==2 then B2 set at  -1,0,1 and will correctly set B2 to 0 at pole rj=2
          rjstag0 = rj0;
          deathstagjs0 = 0-poledeathreal+1;
          deathstagje0 = 0+poledeathreal-1;

          rjstagtest = rjtest;
          deathstagjstest = deathstagjs0-DEATHEXPANDAMOUNT;
          deathstagjetest = deathstagje0+DEATHEXPANDAMOUNT;
          if(deathstagjstest<inoutlohi[POINTDOWN][POINTDOWN][2]) deathstagjstest=inoutlohi[POINTDOWN][POINTDOWN][2];
          if(deathstagjetest<inoutlohi[POINTDOWN][POINTDOWN][2]) deathstagjetest=inoutlohi[POINTDOWN][POINTDOWN][2];

          // assumes velocity is always CENT
          gammadeathjs=0-polegammadeathreal;
          gammadeathje=0+polegammadeathreal-1;
          if(gammadeathjs<inoutlohi[POINTDOWN][POINTDOWN][2]) gammadeathjs=inoutlohi[POINTDOWN][POINTDOWN][2];
          if(gammadeathje<inoutlohi[POINTDOWN][POINTDOWN][2]) gammadeathje=inoutlohi[POINTDOWN][POINTDOWN][2];

          // NO, don't do below.  Since poledeath called after MPI, need to set ghost cells as consistent with how active cells would have been set by other part of grid or other CPUs
          //    if(special3dspc){
          //      // then assume poledeath called *after* MPI (so have full and correct information across pole), so only should modify active cells and not boundary cells
          //      deathjs0 = 0;
          //      deathjstest = 0;
          //      deathstagjs0 = 0;
          //      deathstagjstest = 0;
          //      gammadeathjs=0;
          //    }
          //////////////////////////////////////

        }
        else if(whichx2==X2UP){


          bl_coord_ijk(i,N2BND,k,CENT,Vtemp);
          if(Vtemp[1]>RADIUSMOREDEATH){
            poledeathreal=N2BND;
            polegammadeathreal=N2BND;
          }
          else{
            poledeathreal=POLEDEATH;
            polegammadeathreal=POLEGAMMADEATH;
          }

          rj0=N2-1-poledeathreal;
          rjtest = rj0-DEATHEXPANDAMOUNT;
          poleloc=N2;
          poleloccent=N2-1;
          // if poledeathreal==2 then CENTs set at N2-2,N2-1,N2,N2+1 rj=N2-3
          deathjs0 = N2-1+1-poledeathreal;
          deathje0 = N2-1+poledeathreal;

          deathjstest = deathjs0-DEATHEXPANDAMOUNT;
          deathjetest = deathje0+DEATHEXPANDAMOUNT;
          if(deathjstest>inoutlohi[POINTUP][POINTUP][2]) deathjstest=inoutlohi[POINTUP][POINTUP][2];
          if(deathjetest>inoutlohi[POINTUP][POINTUP][2]) deathjetest=inoutlohi[POINTUP][POINTUP][2];

          // if poledeathreal==2, then B2 is set at N2-1,N2,N2+1 rj=N2-3
          if(dirprim[B2]==FACE2) rjstag0=N2-poledeathreal;
          else if(dirprim[B2]==CENT) rjstag0=rj0;
          deathstagjs0 = N2+1-poledeathreal;
          deathstagje0 = N2-1+poledeathreal;

          rjstagtest = rjtest;
          deathstagjstest = deathstagjs0-DEATHEXPANDAMOUNT;
          deathstagjetest = deathstagje0+DEATHEXPANDAMOUNT;
          if(deathstagjstest>inoutlohi[POINTUP][POINTUP][2]) deathstagjstest=inoutlohi[POINTUP][POINTUP][2];
          if(deathstagjetest>inoutlohi[POINTUP][POINTUP][2]) deathstagjetest=inoutlohi[POINTUP][POINTUP][2];


          // assumes velocity is always CENT .  If POLEDEATH==2, N2-2,N2-1,N2,N2+1
          gammadeathjs = N2-1+1-polegammadeathreal;
          gammadeathje = N2-1+polegammadeathreal;
          if(gammadeathjs>inoutlohi[POINTUP][POINTUP][2]) gammadeathjs=inoutlohi[POINTUP][POINTUP][2];
          if(gammadeathje>inoutlohi[POINTUP][POINTUP][2]) gammadeathje=inoutlohi[POINTUP][POINTUP][2];


          //    if(special3dspc){
          //      // then assume poledeath called *after* MPI (so have full and correct information across pole), so only should modify active cells and not boundary cells
          //      deathje0 = N2-1;
          //      deathjetest = N2-1;
          //      deathstagje0 = N2-1;
          //      deathstagjetest = N2-1;
          //      gammadeathje=N2-1;
          //    }

        }
        //////////////////////////////////////


        if(LIMITEDPOLEDEATHINRADIUS){
          FTYPE Rhorref=rhor_calc(0);
          if(ispstag==0){
            // even problems with poledeath for within horizon, can lead to Erf blowing up, so why 1|| below
            if(  (1||startpos[1]+i>N1BND || Vtemp[1]>0.9*Rhorref) && (Vtemp[1]<OUTERDEATHRADIUS && OUTERDEATH==1 || OUTERDEATH==0)) continue;
          }
        }



        for (j = gammadeathjs; j <= gammadeathje; j++) { // currently not multiple-point dependent, so normal j loop is fine


          //////////////
          //
          // setup initial pr (already using pl, so use pl2 for prdiag assignment/setup)
          //
          //////////////
          PBOUNDLOOP(pliter,pl2) prdiag[pl2]=MACP0A1(prim,i,j,k,pl2);
          int madechange=0;


          ///////////
          //
          // forever-kept debug
          //
          ///////////
          PBOUNDLOOP(pliter,pl2){
            if( !isfinite( MACP0A1(prim,i,j,k,pl2))){
              dualfprintf(fail_file,"BNDNAN: ispstag=%d t=%21.15g nstep=%ld steppart=%d :: i=%d j=%d k=%d pl2=%d prim=%21.15g\n",ispstag,t,nstep,steppart,i,j,k,pl2,MACP0A1(prim,i,j,k,pl2));
            }
          }



          ///////////
          //
          // get u^r and limit if necessary
          //
          ///////////
          get_geometry(i, j, k, dirprim[pl], ptrgeom[pl]);

          ucon_calc(&MACP0A1(prim,i,j,k,0),ptrgeom[pl],ucon, others);
          if(URAD0>=0){
            ucon_calc(&MACP0A1(prim,i,j,k,URAD1-U1),ptrgeom[pl],uconrad, othersrad);
          }
          // only limit velocity if outgoing relative to grid (GODMARK: only valid in KS or BL-like coordinates such that u^r>0 means outgoing w.r.t. an observer at infinity)
          //          if(ucon[RR]>0.0||uconrad[RR]>0.0){

          // get V[RR]
          bl_coord_ijk_2(i,j,k,dirprim[pl],X[pl],V[pl]);


          // check if did limit
          int didlimit=0;

          /////////////
          //
          // FLUID
          //
          /////////////
          gammavaluelimit = GAMMAMAX; // default is no limit

          if(V[pl][RR]>GAMMAPOLEOUTGOINGRADIUSIN){

            if(V[pl][RR]<=GAMMAPOLEOUTGOINGRADIUS){
              // flat \gamma limit up to GAMMAPOLEOUTGOINGRADIUS
              if(ucon[RR]>0.0){
                didlimit=1;
                gammavaluelimit = GAMMAPOLEOUTGOING;
              }
              else if(ucon[RR]<0.0){
                didlimit=1;
                gammavaluelimit = GAMMAPOLEINGOINGOUT;
              }
              else  gammavaluelimit = GAMMAMAX;

            }
            else{
              if(1||ucon[RR]>0.0){ // both ingoing and outgoing components limited in same way
                didlimit=1;
                gammavaluelimit = GAMMAPOLEOUTGOING*pow(V[pl][RR]/GAMMAPOLEOUTGOINGRADIUS,GAMMAPOLEOUTGOINGPOWER);
                gammavaluelimit=MIN(gammavaluelimit,GAMMAPOLEOUTGOINGMAX);
              }
              else gammavaluelimit=GAMMAMAX;

            }

          }// end if u^r>0
          else{
            didlimit=1;
            gammavaluelimit=GAMMAPOLEINGOING;
          }



          /////////////
          //
          // RADIATION
          //
          /////////////
          gammaradvaluelimit = GAMMAMAXRAD; // default is no limit

          if(URAD0>=0){
            if(V[pl][RR]>GAMMARADPOLEOUTGOINGRADIUSIN){
              
              if(V[pl][RR]<=GAMMARADPOLEOUTGOINGRADIUS){

                if(uconrad[RR]>0.0){
                  didlimit=1;
                  gammaradvaluelimit = GAMMARADPOLEOUTGOING;
                }
                else if(uconrad[RR]<0.0){
                  didlimit=1;
                  gammaradvaluelimit = GAMMARADPOLEINGOINGOUT;
                }
                else  gammaradvaluelimit = GAMMAMAXRAD;
              }
              else{
                if(1||uconrad[RR]>0.0){ // both ingoing and outgoing components limited in same way
                  didlimit=1;
                  gammaradvaluelimit = GAMMARADPOLEOUTGOING*pow(V[pl][RR]/GAMMARADPOLEOUTGOINGRADIUS,GAMMARADPOLEOUTGOINGPOWER);
                  gammaradvaluelimit=MIN(gammaradvaluelimit,GAMMARADPOLEOUTGOINGMAX);
                }
                else gammaradvaluelimit=GAMMAMAXRAD;
              }
            }// end if u^r>0
            else{
              didlimit=1;
              gammaradvaluelimit=GAMMARADPOLEINGOING;
            }
          }


          //////////////////
          //
          // Limit gamma's
          //
          //////////////////
          if(didlimit){
            //if(j==0 && (ucon[TT]>10 || uconrad[TT]>10)){ // DEBUG
            //                  dualfprintf(fail_file,"GODHERE1: ur=%g %g : ut=%g %g : limit= %g %g\n",ucon[RR]*sqrt(ptrgeom[pl]->gcov[GIND(RR,RR)]),uconrad[RR]*sqrt(ptrgeom[pl]->gcov[GIND(RR,RR)]),ucon[TT],uconrad[TT],gammavaluelimit,gammaradvaluelimit);
            //}

            limit_gamma(0,gammavaluelimit,gammaradvaluelimit,MAC(prim,i,j,k),NULL,ptrgeom[pl],-1);

            //              if(j==0 && (ucon[TT]>10 || uconrad[TT]>10)){ // DEBUG
            //                ucon_calc(&MACP0A1(prim,i,j,k,0),ptrgeom[pl],ucon, others);
            //                if(URAD0>=0){
            //                  ucon_calc(&MACP0A1(prim,i,j,k,URAD1-U1),ptrgeom[pl],uconrad, othersrad);
            //                }
            //                dualfprintf(fail_file,"GODHERE2: ur=%g %g : ut=%g %g : limit= %g %g\n",ucon[RR]*sqrt(ptrgeom[pl]->gcov[GIND(RR,RR)]),uconrad[RR]*sqrt(ptrgeom[pl]->gcov[GIND(RR,RR)]),ucon[TT],uconrad[TT],gammavaluelimit,gammaradvaluelimit);
            //              }
            madechange++;
          }



          //////////////////
          //
          // Accounting for gamma changes
          //
          //////////////////
          if(madechange&&candodiag){
            ///////////
            //
            // accounting for on-grid changes
            //
            ////////////
            int modcons=(DOENOFLUX != NOENOFLUX);
            FTYPE *ucons;
            ucons=GLOBALMAC(unewglobal,i,j,k); // GODMARK -- need to pass ucons to bounds if really want !=NOENOFLUX method to work
            // GODMARK: assume all quantities at the same location since ispstag==0 is assumed in this section, so ptrgeom[pl]->ptrgoem
            // in general, not sure which pl2 really exists at this point, so pick first in PBOUNDLOOP loop
            struct of_geom *fixupptrgeom;
            //     PBOUNDLOOP(pliter,pl2) {
            pl2=pl;  // only 1 ptrgeom defined
            fixupptrgeom=ptrgeom[pl2];
            //       break;
            //     }
     
            PBOUNDLOOP(pliter,pl2) pr[pl2]=MACP0A1(prim,i,j,k,pl2);
            int doingmhdfixup=1;
            diag_fixup(modcons,prdiag,pr,ucons,fixupptrgeom,finalstep,doingmhdfixup,COUNTBOUND2);
            PBOUNDLOOP(pliter,pl2) prdiag[pl2]=pr[pl2];

          }


        }// end over j
      }// end loop 13
    }// end if ispstag==0
  }// end if POLEGAMMADEATH



  return(0);


}







#define DEBUGPOLESMOOTH 0

/// Average quasi-Cartesian components around the polar axis
/// Note that if special3dspc==1, then bound_x2dn/x2up_polaraxis_full3d() [that calls poledeath() and/or polesmooth()] is called *after* MPI call in bound_prim_user_after_mpi_dir()
/// If special3dspc==0, then not accurately handling polar axis so can't expect polesmooth() to be as effective.
int polesmooth(int whichx2,
               int boundstage, int finalstep, SFTYPE boundtime, int whichdir, int boundvartype, int *dirprim, int ispstag, FTYPE (*prim)[NSTORE2][NSTORE3][NPR],
               int *inboundloop,
               int *outboundloop,
               int *innormalloop,
               int *outnormalloop,
               int (*inoutlohi)[NUMUPDOWN][NDIM],
               int riin, int riout, int rjin, int rjout, int rkin, int rkout,
               int *dosetbc,
               int enerregion,
               int *localenerpos)
{
  
  int i, j, k;
  int j0, dj, stopj, rj;
  int fakej;
  FTYPE X[NDIM], V[NDIM];
  FTYPE r, th, ph;
  FTYPE dxdxp[NDIM][NDIM], idxdxp[NDIM][NDIM];
  FTYPE *pr;
  static FTYPE *fullpr;
  FTYPE cartavgpr[NPR], spcavgpr[NPR],spcpr[NPR];
  static int firsttime=1;
  int pliter,pl;

  //  return(0);




  /////////////////////
  //
  // Check/report some conditions to ensure can allow polesmooth()
  //
  /////////////////////

  // no need to process staggered primitive that are currently only field components
  if(ispstag) return(0);

  if(firsttime && special3dspc==0 && N3>1){ // not valid use of polesmooth()
    dualfprintf(fail_file,"SUPERWARNING: Must enable special3dspc==1 for it to be useful when N3>1\n");
  }

  if(firsttime && dofull2pi==0 && N3>1){
    dualfprintf(fail_file,"SUPERWARNING: Must enable dofull2pi==1 and have full 2\\pi doain when using polesmooth() for it to be useful when N3>1\n");
  }


#if(DEBUGPOLESMOOTH)
  dualfprintf(fail_file,"Got here t=%g\n",t);
#endif









  /////////////////////
  //
  // Allocate full span required for each myid
  //
  /////////////////////
  // need k slowest index so can easily do MPI sends/receives
#define MAPFULLPR(i,fakej,k,pl) ( (fakej)*(N3BND+N3+N3BND)*(N1BND+N1+N1BND)*NPR + ((k)+N3BND)*(N1BND+N1+N1BND)*NPR + ((i)+N1BND)*NPR + (pl) )
  // so access as: fullpr[MAPFULLPR(i,fakej,k,pl)]  .  Order of i,fakej,k,pl is just to be similar to normal order of i,j,k,pl
#define N1TOTFULLPR (N1BND+N1+N1BND)
#define N2TOTFULLPR (ncpux3>1&&USEMPI&&N3>1 ? 1 : 2) // need 2 j positions if single cpu
#define N3TOTFULLPR (N3BND+totalsize[3]+N3BND)
  if(firsttime){
    // not necessary if USEMPI==0 or ncpux3==1, but still do since not expensive
    fullpr=(FTYPE *)malloc(sizeof(FTYPE)*(N2TOTFULLPR*N3TOTFULLPR*N1TOTFULLPR*NPR));
    if(fullpr==NULL){
      dualfprintf(fail_file,"Cannot allocate fullpr\n");
      myexit(195367346);
    }
    // fullpr never freed, but repeatedly used
  }




  /////////////////////
  //
  // Setup which j=rj to use as reference and Setup interior j loop
  //
  //////////////////////
  if (whichx2==X2DN) {
    j0 = -POLESMOOTH; //starting from this j including this j
    rj = POLESMOOTH;  //until this j but not including this j
    dj = 1;
    //    stopj=rj+1; // can also average-out j=rj
    stopj=rj;
    fakej=0;
  }
  else{
    j0 = N2-1+POLESMOOTH;  //starting from this j including this j
    rj = N2-1-POLESMOOTH; //until this j but not including this j
    dj = -1;
    //    stopj=rj-1; // can also average-out j=rj
    stopj=rj;
    if(N2TOTFULLPR==1) fakej=0;
    else fakej=1; // 2 j memory slots since on 1 cpu
  }




  //////////////////////////////
  //
  // if MPI, then setup memory and pre-post recv's
  //
  ////////////////////////////
  static MPI_Request *srequest;
  static MPI_Request *rrequest;

  if(USEMPI && ncpux3>1 && N3>1){

    if(firsttime){
      srequest=(MPI_Request *)malloc(sizeof(MPI_Request)*ncpux3);
      if(srequest==NULL){
        dualfprintf(fail_file,"Cannot allocate srequest\n");
        myexit(19523766);
      }
      rrequest=(MPI_Request *)malloc(sizeof(MPI_Request)*ncpux3);
      if(rrequest==NULL){
        dualfprintf(fail_file,"Cannot allocate rrequest\n");
        myexit(346962762);
      }
    }



    if(mycpupos[2]==0 || mycpupos[2]==ncpux2-1){ // only done for j=rj near physical poles
      int posk;
      
      // transfer myid mycpupos[3] pr data to all other relevant cores (all other cores at this mycpupos[1],mycpupos[2] for all mycpupos[3])
      // non-blocking (all sends's occur at once)

      // receive all other portions of pr and fill local myid's fullpr data
      // non-blocking (all recv's occur at once)

      int count=N3*N1M*NPR;

      for(posk=0;posk<ncpux3;posk++){ // posk is absolute mycpupos[3] value
        if(posk!=mycpupos[3]){

          int originmyid=posk*ncpux2*ncpux1 + mycpupos[2]*ncpux1 + mycpupos[1];
          int recvtag=TAGSTARTBOUNDMPIPOLESMOOTH + originmyid + numprocs*mycpupos[3]; // recvtag used by other myid.  Receiving for my mycpupos[3]

          // do recv
          MPI_Irecv(&fullpr[MAPFULLPR(-N1BND,fakej,posk*N3,0)] , count , MPI_FTYPE , MPIid[originmyid] , recvtag , MPI_COMM_GRMHD , &rrequest[posk]);
#if(DEBUGPOLESMOOTH)
          dualfprintf(fail_file,"MPI_Irecv: posk=%d : %d %d\n",posk,originmyid,recvtag);
#endif

        }
      }
    }
  }












  ////////////
  //
  // fullpr contains SPC versions of U1-U3 and PRIMECOORDS versions of other things (including scalars)
  // fill-in myid portion of fullpr
  // only a single j=rj
  //
  ////////////
  // do LOOPF1 in case near physical inner-radial or outer-radial boundaries that have already been set otherwise
  // Do transformation to SPC and Cart here to keep calculation distributed *and* because otherwise would have to fix "k" since don't have dxdxp or bl_coord stored for other k off this MPI process.
  LOOPF1 LOOPN3{

    /////////////////////////////////////////
    // TRANSFORM PRIMECOORDS to quasi-SPC    
    // Do here during fullpr store instead of later, because otherwise have to assume dxdxp[] does not vary in k and have to choose fixed k for dxdxp
    dxdxprim_ijk(i, rj, k, CENT, dxdxp);
    // No need to get_geometry() (that would be used to get lab-frame quantities) or to get ucon using pr2ucon().  Just process original frame quantities.
    // No need to get dxdxp using dxdxpprim_ijk() near pole except to obtain dominant scale.  Major issue is twisting of coordinates, and dxdxp[1,2] and dxdxp[2,1] aren't large enough near pole to introduce major twisting.

    // set pr to pull from prim[]
    pr = MAC(prim,i,rj,k);

    ///////////////////
    // TRANSFORM PRIMECOORDS -> quasi-SPC
    PBOUNDLOOP(pliter,pl) if(pl<U1 || pl>B3) spcpr[pl] = pr[pl];

    // get quasi-SPC coordinates (avoid use of full dxdxp -- just need to get dimensional scalings correct for most part)
    spcpr[U1]=dxdxp[RR][RR]*pr[U1] + dxdxp[RR][TH]*pr[U2];
    spcpr[U2]=dxdxp[TH][RR]*pr[U1] + dxdxp[TH][TH]*pr[U2];
    spcpr[U3]=dxdxp[PH][PH]*pr[U3];


    // store in fullpr the SPC versions of U1-U3 and other scalars.  Might as well avoid B1-B3 overwritten later.
    PBOUNDLOOP(pliter,pl)  if(pl<B1 || pl>B3) fullpr[MAPFULLPR(i,fakej,mycpupos[3]*N3+k,pl)] = spcpr[pl];

    /////////////////////////////////////////
    // TRANSFORM quasi-SPC to quasi-CART
    // quasi-Cart x, y, z (see tiltedAphi.m)
    // Do here so bl_coord() doesn't have to use fixed k or recompute for non-stored k values if looping over totalsize[3] per core later
    // get SPC V=t,r,\theta,\phi
    bl_coord_ijk_2(i,rj,k,CENT,X,V);
    r = V[1];
    th = V[2];
    ph = V[3];
    // No need to get_geometry() (that would be used to get lab-frame quantities) or to get ucon using pr2ucon().  Just process original frame quantities.
    // No need to get dxdxp using dxdxpprim_ijk() near pole except to obtain dominant scale.  Major issue is twisting of coordinates, and dxdxp[1,2] and dxdxp[2,1] aren't large enough near pole to introduce major twisting.
    
    // put CART[U1-U3] into prfull[B1-B3] for storage
    fullpr[MAPFULLPR(i,fakej,mycpupos[3]*N3+k,B1)] = -(r*sin(ph)*sin(th)*spcpr[U3]) + cos(ph)*sin(th)*spcpr[U1] + r*cos(ph)*cos(th)*spcpr[U2];
    fullpr[MAPFULLPR(i,fakej,mycpupos[3]*N3+k,B2)] = r*cos(ph)*sin(th)*spcpr[U3] + sin(ph)*sin(th)*spcpr[U1] + r*cos(th)*sin(ph)*spcpr[U2];
    fullpr[MAPFULLPR(i,fakej,mycpupos[3]*N3+k,B3)] = cos(th)*spcpr[U1] - r*sin(th)*spcpr[U2];

#if(DEBUGPOLESMOOTH)
    PBOUNDLOOP(pliter,pl) dualfprintf(fail_file,"Got hereINITIAL: t=%g i=%d j=%d k=%d : pl=%d pr=%g spc=%g cart=%g i/dxdxp11=%g %g\n",t,i,j,k,pl,pr[pl],spcpr[pl],fullpr[MAPFULLPR(i,fakej,mycpupos[3]*N3+k,pl)],idxdxp[RR][RR],dxdxp[RR][RR]);
#endif
  }








  //////////////////////////////
  //
  // if MPI, then send my portion to other posk's and insert portions from all other posk's
  //
  ////////////////////////////
  if(USEMPI && ncpux3>1 && N3>1){
    MPI_Status mpistatus;



    if(mycpupos[2]==0 || mycpupos[2]==ncpux2-1){ // only done for j=rj near physical poles
      int posk;
      
      // transfer myid mycpupos[3] pr data to all other relevant cores (all other cores at this mycpupos[1],mycpupos[2] for all mycpupos[3])
      // non-blocking (all sends's occur at once)

      // receive all other portions of pr and fill local myid's fullpr data
      // non-blocking (all recv's occur at once)

      int count=N3*N1M*NPR;

      // do sends, with option to handshake first to ensure recv is ready and posted to avoid unexpected messages filling up buffer.
      for(posk=0;posk<ncpux3;posk++){ // posk is absolute mycpupos[3] value
        if(posk!=mycpupos[3]){
   
          int originmyid=posk*ncpux2*ncpux1 + mycpupos[2]*ncpux1 + mycpupos[1];
          int recvtag=TAGSTARTBOUNDMPIPOLESMOOTH + originmyid + numprocs*mycpupos[3]; // recvtag used by other myid.  Receiving for my mycpupos[3]
   
          int destmyid=posk*ncpux2*ncpux1 + mycpupos[2]*ncpux1 + mycpupos[1];
          int sendtag=TAGSTARTBOUNDMPIPOLESMOOTH + myid + numprocs*posk; // sending to mycpupos[3]=posk (large sendtag space to ensure no duplicates)
   
          if(MPIFLOWCONTROL==1){
            // handshake before each send but after all recv's posted
            int nothingsend=0;
            int nothingrecv=0;
            int maxtag = numprocs*ncpux3; // might be somewhat limiting on numprocs for large number of ncpux3
     
            MPI_Sendrecv(
                         &nothingsend,0,MPI_INT,
                         MPIid[destmyid],
                         maxtag + sendtag,
    
                         &nothingrecv,0,MPI_INT,
                         MPIid[originmyid],
                         maxtag + recvtag,
    
                         MPI_COMM_GRMHD,MPI_STATUS_IGNORE);
     
          } // end if doing FLOWCONTROL


          // now send
          MPI_Isend(&fullpr[MAPFULLPR(-N1BND,fakej,mycpupos[3]*N3,0)] , count , MPI_FTYPE , MPIid[destmyid] , sendtag , MPI_COMM_GRMHD , &srequest[posk]);
#if(DEBUGPOLESMOOTH)
          dualfprintf(fail_file,"MPI_Isend: posk=%d : %d %d\n",posk,destmyid,sendtag);
#endif
        }
      }

      

      

      // wait for all data to be recv'ed before moving to average that uses fullpr data and requires all data to be present in fullpr
      // wait for recv's
      for(posk=0;posk<ncpux3;posk++){
        if(posk!=mycpupos[3]){
          MPI_Wait(&rrequest[posk],&mpistatus); // assume successful so don't check mpistatus
#if(DEBUGPOLESMOOTH)
          dualfprintf(fail_file,"MPI_Wait: posk=%d\n",posk);
#endif
        }
      }


      // finally wait for sends
      for(posk=0;posk<ncpux3;posk++){
        if(posk!=mycpupos[3]){
          MPI_Wait(&srequest[posk],&mpistatus); // assume successful so don't check mpistatus
#if(DEBUGPOLESMOOTH)
          dualfprintf(fail_file,"MPI_Wait: posk=%d\n",posk);
#endif
        }
      }


    }// end if physical polar myid
  }// end if USEMPI and ncpux3>1 so have to transfer to other procs


#if(DEBUGPOLESMOOTH)
  LOOPF1 for(k=0;k<totalsize[3];k++){
    PBOUNDLOOP(pliter,pl) if(pl==RHO || pl==B3) dualfprintf(fail_file,"FULLPRCHECK: i=%d k=%d pl=%d fullpr=%g\n",i,k,pl,fullpr[MAPFULLPR(i,fakej,k,pl)]);
  }
#endif




  /////////////////////
  //
  // Loop over i (per i, no averaging or extrapolation in i)
  //
  //////////////////////
  LOOPF1{ // full i to account for already-assigned real boundary cells


#if(DEBUGPOLESMOOTH)
    dualfprintf(fail_file,"Got here t=%g i=%d\n",t,i);
#endif

    //////////
    //
    // zero-out cumulating primitives
    //
    //////////
    PBOUNDLOOP(pliter,pl){
      cartavgpr[pl]=0.0;
      spcavgpr[pl]=0.0;
    }

   

    ///////////////
    //
    // loop over totalsize[3] for k and obtain average
    //
    ////////////////
    for(k=0;k<totalsize[3];k++){ // only over active domain for averaging.  Over full-k for fullpr

#if(DEBUGPOLESMOOTH)
      dualfprintf(fail_file,"Got here t=%g i=%d k=%d\n",t,i,k);
#endif
      
      // Averaged quasi-SPC versions (note spcavgpr[B1-B3] not used and fullpr[B1-B3] stored quasi-CART U1-U3, so might as well avoid B1-B3)
      PBOUNDLOOP(pliter,pl) if(pl<B1 || pl>B3) spcavgpr[pl] += fullpr[MAPFULLPR(i,fakej,k,pl)];

      // Averaged non-velocities for quasi-CART (avoid cartavgpr[pl=U1-U3] that cumulate next.  Also go ahead and avoid B1-B3 since fullpr[B1-B3] filled will cart U1-U3
      PBOUNDLOOP(pliter,pl) if(pl<U1 || pl>B3) cartavgpr[pl] += fullpr[MAPFULLPR(i,fakej,k,pl)];

      // cumulate quasi-CART U1-U3 (stored in fullpr[B1-B3])
      cartavgpr[U1] += fullpr[MAPFULLPR(i,fakej,k,B1)];
      cartavgpr[U2] += fullpr[MAPFULLPR(i,fakej,k,B2)];
      cartavgpr[U3] += fullpr[MAPFULLPR(i,fakej,k,B3)];

    }// end cumulation over k at j=rj


    /////////////
    //
    // Obtain average by dividing by numer of terms (assume use *all* \phi cells per i,j)
    // for USEMPI==1 && ncpux3>1, assume all CPUs got same average so no need to share average.  Will be same to machine precision, which is sufficient since no inconsistency across MPI boundaries in the end -- these machine errors just make average different for each k, which is perfectly fine.
    //
    /////////////
    PBOUNDLOOP(pliter,pl){
      if(pl<B1 || pl>B3){ // skip unused B1-B3
        cartavgpr[pl] /= (FTYPE)totalsize[3];
        spcavgpr[pl]  /= (FTYPE)totalsize[3];
      }
    }

    // account for dofull2pi==0 or 2D axisymmetry
    // in such a case, can't have net flow across axis
    // (so similar to poledeath() in 2D limit or not-fully-3d dofull2pi=0 limit)
    if(dofull2pi==0 || totalsize[3]==1){
      cartavgpr[U1] = 0.0; // net vx=0 across axis
      cartavgpr[U2] = 0.0; // net vy=0 across axis
    }

#if(DEBUGPOLESMOOTH)
    PBOUNDLOOP(pliter,pl) dualfprintf(fail_file,"Got hereCARTSPC: t=%g i=%d pl=%d %g %g\n",t,i,pl,cartavgpr[pl],spcavgpr[pl]);
#endif



    //////////////
    //    
    // Populate the interior (to stopj) j cells with averaged primitives
    //
    //////////////
    LOOPF3{// over full domain for assignment of the average since boundary call for periodic x3 may already (as is normal) be done.
      for (j=j0; j != stopj; j+=dj) { // over interior j to stopj that is (typically) rj


        //////////////////////////////////////////////////
        // TRANSFORM CART to quasi-SPC
        // Current interior-pole location (j, which is inside previous rj location)
        bl_coord_ijk_2(i,j,k,CENT,X,V);
        r = V[1];
        th = V[2];
        ph = V[3];

        // Set non-velocity SPC (cartavgpr[B1-B3] has nothing, so avoid)
        PBOUNDLOOP(pliter,pl) if(pl<U1 || pl>B3) spcpr[pl] = spcavgpr[pl]; // could also use cartavgpr too.  Same results for scalars.
 
        // Set quasi-SPC for i,j,k from phi-averaged quasi-Cart from i,j=rj,all k
        // just inverse transformation of above cartavgpr(pr)
        spcpr[U1] = cos(ph)*sin(th)*cartavgpr[U1] + sin(ph)*sin(th)*cartavgpr[U2] + cos(th)*cartavgpr[U3];
        spcpr[U2] = pow(r,-1)*(cos(ph)*cos(th)*cartavgpr[U1] + cos(th)*sin(ph)*cartavgpr[U2] - sin(th)*cartavgpr[U3]);
        spcpr[U3] = (1./sin(th))*pow(r,-1)*(-sin(ph)*cartavgpr[U1] + cos(ph)*cartavgpr[U2]);

        // The average of v_x and v_y around axis removes rotation around axis, so add back-in the phi-averaged rotational velocity
        spcpr[U3] += spcavgpr[U3];

        // TODOMARK GODMARK: Why not also add back-in average compression/expansion around axis in \theta direction by doing:
        // Might be better for shocks near axis
        // spcpr[U2] += spcavgpr[U2];

        // NOTEMARK: spcpr[U1]=r is just like cartavgpr[U3]=z, so no recovery of net motion required.


        //////////////////////////////////////////////////
        // TRANSFORM quasi-SPC to PRIMECOORDS

        // set pr to assign
        pr = MAC(prim,i,j,k);

        // Set other non-velocity, non-field things (DO NOT OVERWRITE FIELD!)
        PBOUNDLOOP(pliter,pl) if(pl<U1 || pl>B3) pr[pl] = spcpr[pl];

        // Since using simplified dxdxp above, must use inverse of that for consistency.  Cannot use full idxdxp unless used full dxdxp.
        // idxdxprim_ijk(i, j, k, CENT, idxdxp);
        dxdxprim_ijk(i, j, k, CENT, dxdxp);
        idxdxp[RR][RR]=dxdxp[TH][TH]/(dxdxp[TH][TH]*dxdxp[RR][RR]-dxdxp[TH][RR]*dxdxp[RR][TH]);
        idxdxp[RR][TH]=dxdxp[RR][TH]/(dxdxp[TH][RR]*dxdxp[RR][TH]-dxdxp[TH][TH]*dxdxp[RR][RR]);
        idxdxp[TH][RR]=dxdxp[TH][RR]/(dxdxp[TH][RR]*dxdxp[RR][TH]-dxdxp[TH][TH]*dxdxp[RR][RR]);
        idxdxp[TH][TH]=dxdxp[RR][RR]/(dxdxp[TH][TH]*dxdxp[RR][RR]-dxdxp[TH][RR]*dxdxp[RR][TH]);
        idxdxp[PH][PH]=1.0/dxdxp[PH][PH];

        // note that the below idxdp[] is transposed compared to how would act on u_\mu
        pr[U1]=idxdxp[RR][RR]*spcpr[U1] + idxdxp[RR][TH]*spcpr[U2];
        pr[U2]=idxdxp[TH][RR]*spcpr[U1] + idxdxp[TH][TH]*spcpr[U2];
        pr[U3]=idxdxp[PH][PH]*spcpr[U3];

        // DONE!  Have full pr=prim[] set now



        // NOW set boundary conditions consistent with full3d treatment
        // NO!  Boundary cell values only change in \theta, not \phi as physical cells would, for given j.  So no changes to sign should occur.
        // if(j<0 && whichx2==X2DN || j>totalsize[2]-1 && whichx2==X2UP){
        //   pr[U1]*=SIGNFLIP12;
        //   pr[U2]*=SIGNFLIPU2;
        //   pr[U3]*=SIGNFLIPU3;
        //   // Note that B2,B3 are not ever modified, so no need for sign change
        // }


#if(DEBUGPOLESMOOTH)
        PBOUNDLOOP(pliter,pl) dualfprintf(fail_file,"Got hereFINAL: t=%g i=%d j=%d k=%d : pl=%d pr=%g\n",t,i,j,k,pl,pr[pl]);
#endif


      }// end over each j
    }// end over each k


  }// end over each i
  

  firsttime=0;


  return(0);
  
}




/// Toth version (different because emf vs. flux, where emf has extra zone -- otherwise same!
///reset emf's (E_3) at the boundaries in x1-x2 plane to zero
void user1_adjust_fluxcttoth_emfs(SFTYPE time, FTYPE (*prim)[NSTORE2][NSTORE3][NPR], FTYPE (*emf)[NSTORE1+SHIFTSTORE1][NSTORE2+SHIFTSTORE2][NSTORE3+SHIFTSTORE3] )
{
  int i, j, k;
  int dir;
  int dimen;
  int dirsign;


  if(ADJUSTFLUXCT==0){
    // then no need to set EMF's to zero to maintain divb=0, although can choose to still set EMF's to constant along appropriate directions to maintain stationarity all the way up to including the boundary. Not sure why that would be important to maintain.
    return;
  }
  

  if( DOGRIDSECTIONING==0) {  //don't do anything if sectioning not done
    return;
  }

  
  if(BCtype[X1DN]==FIXEDUSEPANALYTIC || BCtype[X1UP]==FIXEDUSEPANALYTIC){
    // only do if fixing BCs, not (e.g.) outflowing

    //x1-dimension
    dimen = 1;
    DIRSIGNLOOP(dirsign){
      dir = DIRFROMDIMEN( dimen, dirsign );

      if(dir==X1DN && BCtype[X1DN]==FIXEDUSEPANALYTIC || dir==X1UP && BCtype[X1UP]==FIXEDUSEPANALYTIC){ // otherwise don't do

        i = dofluxreg[ACTIVEREGION][dir];

        //if boundary is not on this processor, do not modify emf's
        if( i < -MAXBND ) continue;
        if( i > N1-1+MAXBND) continue;

        //the boundary is on the processor, so reset emf's to zero at the boundary
        if(dir==X1UP && BCtype[dir]==FIXEDUSEPANALYTIC){ // i.e. don't reset EMF2=0 for lower boundary since that corresponds to rotation
          COMPFULLLOOPP1_23{ 
            MACP1A0(emf,2,i,j,k) = 0.0;
          }
        }
        COMPFULLLOOPP1_23{ 
          MACP1A0(emf,3,i,j,k) = 0.0;
        }
      }
    }
  }


#if(0) // below not currently used

  //x2-dimension
  dimen = 2;
  

  //SASMARKXXX -- DO demand stationarity at the polar axis
  DIRSIGNLOOP(dirsign){
    dir = DIRFROMDIMEN( dimen, dirsign );

    j = dofluxreg[ACTIVEREGION][dir];

    //if boundary is not on this processor, do not modify emf's
    if( j < -MAXBND ) continue;
    if( j > N2-1+MAXBND ) continue;

    //the boundary is on the processor, so reset emf's to zero at the boundary
    COMPFULLLOOPP1_13{
      MACP1A0(emf,1,i,j,k) = 0.0;
      MACP1A0(emf,3,i,j,k) = 0.0;
    }
  }

  //x3-dimension
  dimen = 3;


  DIRSIGNLOOP(dirsign){
    dir = DIRFROMDIMEN( dimen, dirsign );

    k = dofluxreg[ACTIVEREGION][dir];

    //if boundary is not on this processor, do not modify emf's
    if( k < -MAXBND ) continue;
    if( k > N3-1+MAXBND ) continue;

    //the boundary is on the processor, so reset emf's to zero at the boundary
    COMPFULLLOOPP1_23{
      MACP1A0(emf,1,i,j,k) = 0.0;
      MACP1A0(emf,2,i,j,k) = 0.0;
    }
  }
#endif
  
  
}

/// NOTEMARK: Sasha's 289ddfa614ac0d10c30b2badff2964aa65853fd6 corrects some bugs.
/// STAG version (different because emf vs. flux, where emf has extra zone -- otherwise same!
///reset emf's (E_3) at the boundaries in x1-x2 plane to zero
void user1_adjust_fluxctstag_emfs(SFTYPE time, FTYPE (*prim)[NSTORE2][NSTORE3][NPR], int *Nvec, FTYPE (*fluxvec[NDIM])[NSTORE2][NSTORE3][NPR+NSPECIAL])
{
  int i, j, k;
  int dir;
  int dimen;
  int dirsign;
  
  if(ADJUSTFLUXCT==0){
    // then no need to set EMF's to zero to maintain divb=0, although can choose to still set EMF's to constant along appropriate directions to maintain stationarity all the way up to including the boundary. Not sure why that would be important to maintain.
    return;
  }

  if( DOGRIDSECTIONING==0) {  //don't do anything if sectioning not done
    return;
  }

  
  if(BCtype[X1DN]==FIXEDUSEPANALYTIC || BCtype[X1UP]==FIXEDUSEPANALYTIC){
    // only do if fixing BCs, not (e.g.) outflowing

    //x1-dimension
    dimen = 1;
    DIRSIGNLOOP(dirsign){
      dir = DIRFROMDIMEN( dimen, dirsign );


      if(dir==X1DN && BCtype[X1DN]==FIXEDUSEPANALYTIC || dir==X1UP && BCtype[X1UP]==FIXEDUSEPANALYTIC){ // otherwise don't do

        //if boundary is not on this processor, do not modify emf's
        i = dofluxreg[ACTIVEREGION][dir];
        if( i < -MAXBND ) continue;
        if( i > N1-1+MAXBND) continue;


        //the boundary is on the processor, so reset emf's to zero at the boundary
        COMPFULLLOOPP1_23{
          // EMF[3]:
#if(N1>1)
          MACP1A1(fluxvec,1,i,j,k,B2) = 0.0;
          MACP1A1(fluxvec,1,i,j,k,B1) = 0.0; // always zero
#endif
#if(N2>1)
          MACP1A1(fluxvec,2,i,j,k,B1) = 0.0;
          MACP1A1(fluxvec,2,i,j,k,B2) = 0.0; // always zero
#endif
        }
      }

      
      if(dir==X1UP && BCtype[dir]==FIXEDUSEPANALYTIC){ // i.e. don't reset EMF2=0 for lower boundary since that corresponds to rotation

        //if boundary is not on this processor, do not modify emf's
        i = dofluxreg[ACTIVEREGION][dir];
        if( i < -MAXBND ) continue;
        if( i > N1-1+MAXBND) continue;


        COMPFULLLOOPP1_23{
          // EMF[2]:
#if(N1>1)
          MACP1A1(fluxvec,1,i,j,k,B3) = 0.0;
          MACP1A1(fluxvec,1,i,j,k,B1) = 0.0; // always zero
#endif
#if(N3>1)
          MACP1A1(fluxvec,3,i,j,k,B1) = 0.0;
          MACP1A1(fluxvec,3,i,j,k,B3) = 0.0; // always zero
#endif
        }
      }


    }
  }

  
  
}






/// adjust final fluxes
/// NOT USED
void user1_adjust_final_fluxes(SFTYPE time, FTYPE (*prim)[NSTORE2][NSTORE3][NPR], int *Nvec, FTYPE (*fluxvec[NDIM])[NSTORE2][NSTORE3][NPR+NSPECIAL])
{
  int i, j, k;
  int dir;
  int dimen;
  int dirsign;
  
  if( DOGRIDSECTIONING==0) {  //don't do anything if sectioning not done
    return;
  }

  
  //x1-dimension
  dimen = 1;
  DIRSIGNLOOP(dirsign){
    dir = DIRFROMDIMEN( dimen, dirsign );


    //if boundary is not on this processor, do not modify emf's
    i = dofluxreg[ACTIVEREGION][dir];
    if( i < -MAXBND ) continue;
    if( i > N1-1+MAXBND) continue;
    
    
    //the boundary is on the processor, so reset emf's to zero at the boundary
    COMPFULLLOOPP1_23{
      // EMF[3]:
#if(N1>1)
      MACP1A1(fluxvec,1,i,j,k,B2) = 0.0;
      MACP1A1(fluxvec,1,i,j,k,B1) = 0.0; // always zero
#endif
#if(N2>1)
      MACP1A1(fluxvec,2,i,j,k,B1) = 0.0;
      MACP1A1(fluxvec,2,i,j,k,B2) = 0.0; // always zero
#endif
      // EMF[2]:
#if(N1>1)
      MACP1A1(fluxvec,1,i,j,k,B3) = 0.0;
      MACP1A1(fluxvec,1,i,j,k,B1) = 0.0; // always zero
#endif
#if(N3>1)
      MACP1A1(fluxvec,3,i,j,k,B1) = 0.0;
      MACP1A1(fluxvec,3,i,j,k,B3) = 0.0; // always zero
#endif
    }
  }


  
  
}





/// check that \detg=0 on singularities
/// Don't use |\theta-0|<small number since can be quite small yet not on singularity
/// use integer-based grid position based detection as consistent with bondary conditions
/// Called for fresh and restart run
/// Runs over PLOOP(pliter,pl)
void check_spc_singularities_user(void)
{
  int i,j,k;
  int poleloop;
  int needzero;
  int singfound;
  int nonsingfound;
  int numlocs=NPG,indloc,loc;
  int pl,pliter;
  LOCALMETRICTEMPVARS;
  int doprintout;

  if(nstep==0) doprintout=1;
  else doprintout=0; // avoid print out when evolving metric and recalling this -- assume faily similar situation as at nstep==0

  ///////////////////////////
  //
  // X1 inner r=0 singularity
  //
  ///////////////////////////


  /* inner radial BC (preserves u^t rho and u) */
  if(mycpupos[1] == 0 && BCtype[X1DN]==R0SING){
    i=0;
      
    //    LOOPX1dir{
    // No, should really be full loops
    LOOPF_23{
    
      for(indloc=0;indloc<numlocs;indloc++){

        if(indloc==0) loc=FACE1;
        else if(indloc==1) loc=CORN3;
        else if(indloc==2) loc=CORN2;
        else if(indloc==3) loc=CORNT;

        // get local metric quantities for this loc,i,j,k
        GETLOCALMETRIC(loc,i,j,k);

        singfound=0;
        singfound+=(localgdet[0]!=0.0);
#if(WHICHEOM!=WITHGDET)
        PLOOP(pliter,pl) singfound+=(LOCALEOMFUNCMAC(pl)!=0.0);
#endif

        if(singfound){
          if(doprintout) dualfprintf(fail_file,"Detected singularity at i=%d j=%d k=%d loc=%d with gdet=%21.15g so resetting it to 0.0\n",i,j,k,loc,localgdet[0]);
          localgdet[0]=0.0;
          if(NEWMETRICSTORAGE){
            GLOBALMETMACP1A0(compgeom,loc,i,j,k).gdet=0.0;
            GLOBALMETMACP1A0(compgeom,loc,i,j,k).igdetnosing=0.0;
            GLOBALMETMACP1A0(gdetgeomnormal,loc,i,j,k).gdet=0.0;
            GLOBALMETMACP1A0(gdetgeomnormal,loc,i,j,k).igdetnosing=0.0;
            GLOBALMETMACP0A1(gdetgeom,i,j,k,loc).gdet=0.0;
            GLOBALMETMACP0A1(gdetgeom,i,j,k,loc).igdetnosing=0.0;
          }
#if(WHICHEOM!=WITHGDET)
          PLOOP(pliter,pl) LOCALEOMFUNCMAC(pl)=0.0;
#endif


        }
      }// end over indloc
    }// end loop 23
  }



  ///////////////////////////
  //
  // X2 POLARAXES
  //
  ///////////////////////////



  if(special3dspc && COORDSINGFIX>0){
    // Then presume really doing 3D problem with \phi direction
    // Then presume that (for simplicity of the method) offsetting pole by \epsilon from \theta=0,\pi so that \detg is generally non-zero
    // Then flux through pole, but transmissive BCs at pole ensure flux into "\epsilon hole" are same as out of the hole on other side
    // In any case that flux is very small.  Key point is that for d_t(\detg B2) = -d_1(\detg E3) + d_3(\detg E1), the small angular term in \detg cancels leaving regular B2 on the pole that enters interpolations of B2.

    // Check that \detg is NOT zero now
    needzero=0;
  }
  else{
    // Then presume no \epsilon offset at pole
    needzero=1;
  }



  for(poleloop=0;poleloop<=1;poleloop++){
    if(poleloop==0 && mycpupos[2] == 0 && BCtype[X2DN]==POLARAXIS){
      j=0;
    }
    else if(poleloop==1 && mycpupos[2] == ncpux2-1 && BCtype[X2UP]==POLARAXIS){
      j=N2-1+SHIFT2;
    }
    else continue;
    
    
    //    LOOPX2dir{
    // No, should really be full loops:
    LOOPF_13{

      for(indloc=0;indloc<numlocs;indloc++){

        if(indloc==0) loc=FACE2;
        else if(indloc==1) loc=CORN3;
        else if(indloc==2) loc=CORN1;
        else if(indloc==3) loc=CORNT;

        // get local metric quantities for this loc,i,j,k
        GETLOCALMETRIC(loc,i,j,k);

        singfound=0;
        singfound+=(fabs(localgdet[0])>0.0);
#if(WHICHEOM!=WITHGDET)
        PLOOP(pliter,pl) singfound+=(fabs(LOCALEOMFUNCMAC(pl))>0.0);
#endif

        nonsingfound=0;
        nonsingfound+=(fabs(localgdet[0])<100*NUMEPSILON);
#if(WHICHEOM!=WITHGDET)
        PLOOP(pliter,pl) nonsingfound+=(fabs(LOCALEOMFUNCMAC(pl))<100*NUMEPSILON);
#endif

        if(needzero && singfound){
          if(doprintout) dualfprintf(fail_file,"Detected singularity at i=%d j=%d k=%d loc=%d with gdet=%21.15g so resetting it to 0.0\n",i,j,k,loc,localgdet[0]);
          localgdet[0]=0.0;
          if(NEWMETRICSTORAGE){
            GLOBALMETMACP1A0(compgeom,loc,i,j,k).gdet=0.0;
            GLOBALMETMACP1A0(compgeom,loc,i,j,k).igdetnosing=0.0;
            GLOBALMETMACP1A0(gdetgeomnormal,loc,i,j,k).gdet=0.0;
            GLOBALMETMACP1A0(gdetgeomnormal,loc,i,j,k).igdetnosing=0.0;
            GLOBALMETMACP0A1(gdetgeom,i,j,k,loc).gdet=0.0;
            GLOBALMETMACP0A1(gdetgeom,i,j,k,loc).igdetnosing=0.0;
          }
#if(WHICHEOM!=WITHGDET)
          PLOOP(pliter,pl) LOCALEOMFUNCMAC(pl)=0.0;
#endif

        }
        else if(needzero==0 && nonsingfound){
          dualfprintf(fail_file,"Detected |\\detg|<=NUMEPSILON at i=%d j=%d k=%d loc=%d with gdet=%21.15g: Must be non-zero\n",i,j,k,loc,localgdet[0]);
          myexit(9813523);
        }
      }// end over indloc
    }// end loop 13
  }// end over poles

}



/// DEBUG special3dspc
/// check matching CPUs have correct information across pole
/// stick in debugspecial3dspc(0, whichdir, ispstag, prim); calls before and after various stages defined through (e.g.) which=0,1,2,3,4,...
int debugspecial3dspc(int which, int whichdir, int ispstag, FTYPE (*prim)[NSTORE2][NSTORE3][NPR])
{
  int i,j,k,pliter,pl;


  dualfprintf(fail_file,"nstep=%ld steppart=%d which=%d whichdir=%d ispstag=%d\n",nstep,steppart,which,whichdir,ispstag);
  for(pl=0;pl<=7;pl++){
    if(ispstag==1 && (pl<5 || pl>7)) continue;
    dualfprintf(fail_file,"pl=%d\n",pl);
    for(k=-N3BND;k<=N3BND;k++){ // was looking at just k=0, but seeing now if all other k are good.
      dualfprintf(fail_file,"k=%d\n",k);
      dualfprintf(fail_file,"%02s | i=\n   ","j");
      for(i=-N1BND;i<=N1BND;i++){
        if(ispstag==1 && (pl==5 && i==-N1BND)) dualfprintf(fail_file,"%021s ","NA");
        else dualfprintf(fail_file,"%19s%02d "," ",i);
      }
      dualfprintf(fail_file,"\n");
      for(j=-N2BND;j<=N2BND;j++){
        dualfprintf(fail_file,"%02d ",j);
        for(i=-N1BND;i<=N1BND;i++){
          if(ispstag==1 && (pl==5 && i==-N1BND || pl==6 && j==-N2BND)) dualfprintf(fail_file,  "%21s ","NA");
          else  dualfprintf(fail_file,  "%21.15g ",MACP0A1(prim,i,j,k,pl));
        }
        dualfprintf(fail_file,"\n");
      }
      dualfprintf(fail_file,"\n");
    }
  }// end over pl


  return(0);

}



/// put the below in your bounds.c function at the top before the above call to that function.
void debugfixupaltdeath_bc_old(FTYPE (*prim)[NSTORE2][NSTORE3][NPR])
{
  // hack to get rid of bad region at large distances (e.g. when restarted)
  int i,j,k;
  struct of_geom geomdontuse;
  struct of_geom *ptrgeom=&geomdontuse;
  FTYPE X[NDIM],V[NDIM];
  FTYPE *prfix,*ufix;
  int jjj;


  FULLLOOP{
    prfix=&MACP0A1(prim,i,j,k,0);//&GLOBALMACP0A1(pglobal,i,j,k,0);
    ufix=&GLOBALMACP0A1(unewglobal,i,j,k,0);
  
    // get geometry for center pre-interpolated values
    get_geometry(i, j, k, CENT, ptrgeom);
    bl_coord_ijk_2(i,j,k,CENT,X, V) ;
  
    //    FTYPE bsq=0.0;
    //    bsq_calc(prfix,ptrgeom,&bsq);


    FTYPE Rbadout=OUTERDEATHRADIUS; //MIN(500.0,0.5*Rout);
    
 
    if(V[1]>Rbadout ){
       
      //prfix[RHO] = 1E-10*pow(V[1]/500.0,-1.5);
  
      prfix[UU]= MIN(prfix[RHO],prfix[UU]); // no more than u/rho=1
      if(DOENOFLUX != NOENOFLUX){
        ufix[UU]=MAX(-prfix[UU],ufix[UU]);
        ufix[ENTROPY] = ufix[UU];
        ufix[ENTROPY] = MAX(0.0001,MIN(ufix[ENTROPY],1.0)); // like u/rho=1
      }

      if(URAD0>=0){
        //prfix[URAD0] = 2E-10*pow(V[1]/500.0,-1.5);
        prfix[URAD0] = MIN(MIN(prfix[RHO],prfix[URAD0]),prfix[UU]); // no more than Erf/rho=1 and Erf/u=1
        if(DOENOFLUX != NOENOFLUX){
          ufix[URAD0]=MAX(-prfix[URAD0],ufix[URAD0]);
        }
      }

      //      limit_gamma(0,1.5,GAMMAMAXRAD,prfix,NULL,ptrgeom,-1);
      limit_gamma(0,OUTERDEATHGAMMAMAX,OUTERDEATHGAMMAMAXRAD,prfix,NULL,ptrgeom,-1);


 
      if(prfix[U1]<0.0){
        prfix[U1]=0.0;
        if(DOENOFLUX != NOENOFLUX){
          ufix[U1]=0.0;
        }
      }
      //      ufix[U2]=ufix[U3]=0.0;
      //      SLOOPA(jjj) ufix[U1+jjj-1]=prfix[U1+jjj-1] = 0.0;
  
      if(URAD0>=0){
        if(prfix[URAD1]<0.0){
          prfix[URAD1]=0.0;
          if(DOENOFLUX != NOENOFLUX){
            ufix[URAD1]=0.0;
          }
        }
      }

    }
  }
}


/// jane:what is used for transition
///put the below in your bounds.c function at the top before the above call to that function.
void debugfixupaltdeath_bc(FTYPE (*prim)[NSTORE2][NSTORE3][NPR])
{
  // hack to get rid of bad region at large distances (e.g. when restarted)
  int i,j,k;
  struct of_geom geomdontuse;
  struct of_geom *ptrgeom=&geomdontuse;
  FTYPE X[NDIM],V[NDIM];
  FTYPE *prfix,*ufix;
  int jjj;

  if(VARTOINTERP==PRIMTOINTERP_GDETFULLVERSION_WALD){

    // 0 : don't do
    // 1: original method
    // 2: new method1
#define AVOIDCS 0

    if(AVOIDCS==1){
      FULLLOOP{
        prfix=&MACP0A1(prim,i,j,k,0);//&GLOBALMACP0A1(pglobal,i,j,k,0);
        ufix=&GLOBALMACP0A1(unewglobal,i,j,k,0);
      
        // get geometry for center pre-interpolated values
        //get_geometry(i, j, k, CENT, ptrgeom);
        //bl_coord_ijk_2(i,j,k,CENT,X, V) ;
      
        //      FTYPE bsq=0.0;
        //      bsq_calc(prfix,ptrgeom,&bsq);
      
      
        // symmetric around equator for centered zones
        int ti=startpos[1]+i;
        int tj=startpos[2]+j;
        int tk=startpos[3]+k;
        if((tj>totalsize[2]/2-3)&&(tj<totalsize[2]/2+2)){
          prfix[U2]=0.0;
        }
      
      }
    }
    else if(AVOIDCS==2){
      FULLLOOP{
      
        // get geometry for center pre-interpolated values
        get_geometry(i, j, k, CENT, ptrgeom);
        bl_coord_ijk_2(i,j,k,CENT,X, V) ;
      
      
        FTYPE Rhorlocal=1.0+sqrt(1.0-a*a);
        //        Rhorlocal=2.0; // use ergosphere instead.
        if(V[1]<Rhorlocal){

          prfix=&MACP0A1(prim,i,j,k,0);//&GLOBALMACP0A1(pglobal,fii,fjj,fkk,0);
          if(DOENOFLUX != NOENOFLUX){
            ufix=&GLOBALMACP0A1(unewglobal,i,j,k,0);
          }
          prfix[U2]=0.0;
        }
      
      }// over FULLLOOP
    }
    else if(AVOIDCS==3){
      FULLLOOP{
      
        // get geometry for center pre-interpolated values
        //get_geometry(i, j, k, CENT, ptrgeom);
        //bl_coord_ijk_2(i,j,k,CENT,X, V) ;
      
      
        FTYPE Rhorlocal=1.0+sqrt(1.0-a*a);
        //        if(V[1]<Rhorlocal){
        FTYPE maxbsq=0.0,mybsq=0.0;
        int ii,jj,kk;
        for(ii=-N1BND;ii<=N1BND;ii++){
          for(jj=-N2BND;jj<=N2BND;jj++){
            for(kk=-N3BND;kk<=N3BND;kk++){
              int fii=MIN(MAX(i+ii,-N1BND),N1-1+N1BND);
              int fjj=MIN(MAX(j+jj,-N2BND),N2-1+N2BND);
              int fkk=MIN(MAX(k+kk,-N3BND),N3-1+N3BND);
              
              prfix=&MACP0A1(prim,fii,fjj,fkk,0);//&GLOBALMACP0A1(pglobal,fii,fjj,fkk,0);
              ufix=&GLOBALMACP0A1(unewglobal,fii,fjj,fkk,0);
              
              
              // get geometry for center pre-interpolated values
              get_geometry(fii,fjj,fkk, CENT, ptrgeom);
              //bl_coord_ijk_2(fii,fjj,fkk,CENT,X, V) ;


              FTYPE bsq=0.0;
              bsq_calc(prfix,ptrgeom,&bsq);

              maxbsq=MAX(maxbsq,bsq);
              
              if(ii==0 && jj==0 && kk==0) mybsq=bsq;
              
            }
          }
        }

        if(mybsq*10.0<maxbsq){

          dualfprintf(fail_file,"i=%d j=%d k=%d mybsq=%g maxbsq=%g\n",i,j,k,mybsq,maxbsq);

          //          prfix=&MACP0A1(prim,i,j,k,0);//&GLOBALMACP0A1(pglobal,fii,fjj,fkk,0);
          //          ufix=&GLOBALMACP0A1(unewglobal,i,j,k,0);
          //          prfix[U2]=0.0;

          for(ii=-N1BND/2;ii<=N1BND/2;ii++){
            for(jj=-N2BND/2;jj<=N2BND/2;jj++){
              for(kk=-N3BND/2;kk<=N3BND/2;kk++){
                int fii=MIN(MAX(i+ii,-N1BND),N1-1+N1BND);
                int fjj=MIN(MAX(j+jj,-N2BND),N2-1+N2BND);
                int fkk=MIN(MAX(k+kk,-N3BND),N3-1+N3BND);
                
                prfix=&MACP0A1(prim,fii,fjj,fkk,0);//&GLOBALMACP0A1(pglobal,fii,fjj,fkk,0);
                ufix=&GLOBALMACP0A1(unewglobal,fii,fjj,fkk,0);
                
                prfix[U2]=0.0;
              }
            }
          }

        }
      
      }// over FULLLOOP
    }

    // do nothing, since when including low density and high b^2/rho, has issues.
    //    return; // flipping back to return because shifting floor in rho,u didn't help MHD heating.
  }
  else{
    // allow outerdeath

    // don't allow in general
    //return;
  }


  if(0){


#define DAMPECOV 0
#define DAMPGAMMA 0
#define OUTERDEATHDAMP 0

    if(DAMPGAMMA || OUTERDEATHDAMP || DAMPECOV){

      FULLLOOP{
        prfix=&MACP0A1(prim,i,j,k,0);//&GLOBALMACP0A1(pglobal,i,j,k,0);
        ufix=&GLOBALMACP0A1(unewglobal,i,j,k,0);
  
        // get geometry for center pre-interpolated values
        get_geometry(i, j, k, CENT, ptrgeom);
        bl_coord_ijk_2(i,j,k,CENT,X, V) ;
  
        FTYPE bsq=0.0;
        bsq_calc(prfix,ptrgeom,&bsq);


        if(DAMPGAMMA){
          if(V[1]>t-100.0 && steppart==0 && nstep%2==0){
            FTYPE gamma,qsq;
            gamma_calc(prfix,ptrgeom,&gamma,&qsq);
            FTYPE gammanew=((gamma-1.0)*0.1)+1.0;
            limit_gamma(0,gammanew,OUTERDEATHGAMMAMAXRAD,prfix,NULL,ptrgeom,-1);
            //prfix[U1]=0.0;
            //dualfprintf(fail_file,"problem: gamma=%g gammanew=%g\n",gamma,gammanew);
          }
        }

        if(DAMPECOV){
          if(V[1]>2.5 && steppart==0 && nstep%2==0){
            extern int init_postvpot(int i, int j, int k, FTYPE *pr, FTYPE *pstag, FTYPE *ucons);
            init_postvpot(i, j, k, prfix, NULL, NULL);
          }
        }

        if(OUTERDEATHDAMP){

          FTYPE Rbadout=OUTERDEATHRADIUS; //MIN(500.0,0.5*Rout);
    
          Rbadout=100.0 + t;
 
          if(V[1]>Rbadout || V[1]>t && (mycpupos[2]==0 && (j<=2) || mycpupos[2]==ncpux2-1 && (j>=N2-1-2)) ){

            if(VARTOINTERP==PRIMTOINTERP_GDETFULLVERSION_WALD){

              FTYPE prfloor[NPR],prceiling[NPR];
              set_density_floors(ptrgeom,prfix,prfloor,prceiling);

              prfix[RHO]=prfloor[RHO];
              prfix[UU]=prfloor[UU];

              limit_gamma(0,OUTERDEATHGAMMAMAX,OUTERDEATHGAMMAMAXRAD,prfix,NULL,ptrgeom,-1);

            }
            else{

       
              //prfix[RHO] = 1E-10*pow(V[1]/500.0,-1.5);
  
              prfix[UU]= MIN(50.0*prfix[RHO],prfix[UU]); // no more than u/rho=10
              //      prfix[UU] = MIN(prfix[UU],
              if(DOENOFLUX != NOENOFLUX){
              ufix[UU]=MAX(-prfix[UU],ufix[UU]);
              ufix[ENTROPY] = ufix[UU];
              ufix[ENTROPY] = MAX(0.0001,MIN(ufix[ENTROPY],1.0)); // like u/rho=1
              }

              if(URAD0>=0){
                //prfix[URAD0] = 2E-10*pow(V[1]/500.0,-1.5);
                prfix[URAD0] = MIN(MIN(prfix[RHO],prfix[URAD0]),prfix[UU]); // no more than Erf/rho=1 and Erf/u=1
                if(DOENOFLUX != NOENOFLUX){
                  ufix[URAD0]=MAX(-prfix[URAD0],ufix[URAD0]);
                }
              }

              //      limit_gamma(0,1.5,GAMMAMAXRAD,prfix,NULL,ptrgeom,-1);
              limit_gamma(0,OUTERDEATHGAMMAMAX,OUTERDEATHGAMMAMAXRAD,prfix,NULL,ptrgeom,-1);

            }
          }


          if(VARTOINTERP==PRIMTOINTERP_GDETFULLVERSION_WALD){

          }
          else{

            FTYPE rbr=500.0;
            FTYPE localrbr=rbr; //500.0; // rbr;
            FTYPE localrbrr0=MAX(100.0,localrbr/2.0);
    
            FTYPE switch0 = 0.5+1.0/M_PI*atan((V[1]-localrbr)/localrbrr0); // large r
            FTYPE switch2 = 1.0-switch0; // small r
            //      FTYPE myhslope1=h0 + pow( (V[1]-rsjet3)/r0jet3 , njet);
            //      FTYPE myhslope2=h0 + pow( (localrbr-rsjet3)/r0jet3 , njet);
            //      myhslope = myhslope1*switch2 + myhslope2*switch0;
    
            if(V[1]<100.0) switch2=1.0;
            //if(V[1]>500.0) switch2=0.0;
    
            if(prfix[U1]<0.0){
              //    switch2=0.0;
              prfix[U1]*=switch2;
              if(DOENOFLUX != NOENOFLUX){
                ufix[U1]*=switch2;
              }
            }
            if(DOENOFLUX != NOENOFLUX){
              //      ufix[U2]=ufix[U3]=0.0;
              //      SLOOPA(jjj) ufix[U1+jjj-1]=prfix[U1+jjj-1] = 0.0;
            }
    
            if(URAD0>=0){
              if(prfix[URAD1]<0.0){
                //switch2=0.0;
                prfix[URAD1]*=switch2;
                if(DOENOFLUX != NOENOFLUX){
                  ufix[URAD1]*=switch2;
                }
              }
            }
          }
        }// end OUTERDEATHDAMP
      }// end FULLLOOP
    }
  }// end if(0)
  else{

    FTYPE prfixtry[NPR],ufixtry[NPR];
    FTYPE prfixtryb[NPR],ufixtryb[NPR];
    int pliter,pl;


    FULLLOOP{
      prfix=&MACP0A1(prim,i,j,k,0);//&GLOBALMACP0A1(pglobal,i,j,k,0);
      ufix=&GLOBALMACP0A1(unewglobal,i,j,k,0);

      PLOOP(pliter,pl) prfixtry[pl]=prfix[pl];
      if(DOENOFLUX != NOENOFLUX){
        PLOOP(pliter,pl) ufixtry[pl]=ufix[pl];
      }

      PLOOP(pliter,pl) prfixtryb[pl]=prfix[pl];
      if(DOENOFLUX != NOENOFLUX){
        PLOOP(pliter,pl) ufixtryb[pl]=ufix[pl];
      }
  
      // get geometry for center pre-interpolated values
      get_geometry(i, j, k, CENT, ptrgeom);
      bl_coord_ijk_2(i,j,k,CENT,X, V) ;
  
      FTYPE bsq=0.0;
      bsq_calc(prfix,ptrgeom,&bsq);

#define BEGINDEATHTRANSITION (OUTERDEATHRADIUS*0.8) //jane: smooth transition from simulation results at this radius to what is set at OUTERDEATHRADIUS

      if(V[1]>OUTERDEATHRADIUS|| V[1]>BEGINDEATHTRANSITION){
    
        FTYPE rbr=OUTERDEATHRADIUS;
        FTYPE localrbr=rbr; //500.0; // rbr;
        FTYPE localrbrr0=BEGINDEATHTRANSITION;
        FTYPE localrbrdr=localrbr/3.0;

#define cr(x) (exp(-1.0/(x)))
#define tr(x) (cr(x)/(cr(x) + cr(1.0-(x))))
#define trans(x,L,R) ((x)<=(L) ? 0.0 : ((x)>=(R) ? 1.0 : tr(((x)-(L))/((R)-(L)))) )
      
        FTYPE switch0,switch2;
        FTYPE switch0b,switch2b;
        FTYPE rinner;

        if(0){
          switch0 = 0.5+1.0/M_PI*atan((V[1]-localrbr)/localrbrdr); // large r
          switch2 = 1.0-switch0; // small r

          switch0b = 0.5+1.0/M_PI*atan((V[1]-localrbr)/localrbrdr); // large r
          switch2b = 1.0-switch0; // small r
        }
        else{
          rinner=MAX(rbr-localrbrdr,BEGINDEATHTRANSITION);
          switch0 = trans(V[1],rinner,rbr+localrbrdr);
          switch2 = 1.0-switch0;

#define FACTORNEXTSWTICH (2.0)
          //rinner=MAX(FACTORNEXTSWTICH*rbr-localrbrdr,BEGINDEATHTRANSITION);
          //switch0b = trans(V[1],rinner,FACTORNEXTSWTICH*rbr+localrbrdr);
          switch0b = trans(V[1],rbr+localrbrdr,FACTORNEXTSWTICH*rbr+localrbrdr);
          switch2b = 1.0-switch0b;
        }
      
        if(V[1]<BEGINDEATHTRANSITION){
          switch0=0.0;
          switch2=1.0;

          switch0b=0.0;
          switch2b=1.0;
        }
        //if(V[1]>500.0) switch2=0.0;




        /// things to change

        //        FTYPE gamma,qsq;
        //        gamma_calc(prfixtry,ptrgeom,&gamma,&qsq);
        //        FTYPE gammanew=OUTERDEATHGAMMAMAX;
        //        limit_gamma(0,gammanew,OUTERDEATHGAMMAMAXRAD,prfixtry,NULL,ptrgeom,-1);
        //prfixtry[U1]=0.0;
        //dualfprintf(fail_file,"problem: gamma=%g gammanew=%g\n",gamma,gammanew);


        //prfixtry[RHO] = 1E-10*pow(V[1]/500.0,-1.5);
      
        prfixtry[UU]= MIN(1.0*prfixtry[RHO],prfixtry[UU]); // no more than u/rho=1
        //      prfixtry[UU] = MIN(prfixtry[UU],
        if(DOENOFLUX != NOENOFLUX){
          ufixtry[UU]=MAX(-prfixtry[UU],ufixtry[UU]);
          ufixtry[ENTROPY] = ufixtry[UU];
          ufixtry[ENTROPY] = MAX(0.0001,MIN(ufixtry[ENTROPY],1.0)); // like u/rho=1
        }
      
        if(URAD0>=0){
          //prfixtry[URAD0] = 2E-10*pow(V[1]/500.0,-1.5);
          //prfixtry[URAD0] = MIN(MIN(prfixtry[RHO],prfixtry[URAD0]),prfixtry[UU]); // no more than Erf/rho=1 and Erf/u=1
          prfixtry[URAD0] = MIN(10.0*prfixtry[RHO],prfixtry[URAD0]); // no more than Erf/rho=10.  No limit on u/prad0 that can be very large in optically thin or thick parts
          if(DOENOFLUX != NOENOFLUX){
            ufixtry[URAD0]=MAX(-prfixtry[URAD0],ufixtry[URAD0]);
          }
        }
      
        //      limit_gamma(0,1.5,GAMMAMAXRAD,prfixtry,NULL,ptrgeom,-1);
        limit_gamma(0,OUTERDEATHGAMMAMAX,OUTERDEATHGAMMAMAXRAD,prfixtry,NULL,ptrgeom,-1);
      
      

#if(1)      
        if(prfixtry[U1]<0.0){
          prfixtry[U1]=0.0;
          if(DOENOFLUX != NOENOFLUX){
            ufixtry[U1]=0.0;
          }
        }
        if(DOENOFLUX != NOENOFLUX){
          //      ufixtry[U2]=ufixtry[U3]=0.0;
          //      SLOOPA(jjj) ufixtry[U1+jjj-1]=prfixtry[U1+jjj-1] = 0.0;
        }
      
        if(URAD0>=0){
          if(prfixtry[URAD1]<0.0){
            prfixtry[URAD1]=0.0;
            if(DOENOFLUX != NOENOFLUX){
              ufixtry[URAD1]=0.0;
            }
          }
        }
#endif

        /////////////////////////////////////////////
        // set b
        PLOOP(pliter,pl){
          prfixtryb[pl] = prfixtry[pl];
          if(DOENOFLUX != NOENOFLUX){
            ufixtryb[pl]  = ufixtry[pl];
          }
        }

#if(1)
        // stronger restrictions for b on prad0
        if(URAD0>=0){
          //FTYPE Tgaslocal=compute_temp_simple(i,j,k,CENT,prfixtryb[RHO],prfixtryb[UU]);
          //          prfixtryb[URAD0] = MIN(MIN(prfixtryb[RHO],prfixtryb[URAD0]),10.0*prfixtryb[UU]); // no more than Erf/rho=1 and Erf/u=10
          prfixtryb[URAD0] = MIN(prfixtryb[RHO],prfixtryb[URAD0]);
          //          prfixtryb[URAD0] = MAX(prfixtryb[URAD0],prfixtryb[UU]); // avoid drop-outs in Erf
          // try thermal equilibrium (arad Tgas^4 = urad )
          //          prfixtryb[URAD0] = calc_LTE_EfromT(Tgaslocal);

          if(DOENOFLUX != NOENOFLUX){
            ufixtryb[URAD0]=MAX(-prfixtryb[URAD0],ufixtryb[URAD0]);
          }
        }
#endif

        // final setting of fixed up quantities
        PLOOP(pliter,pl){
          prfix[pl] = prfixtryb[pl]*switch0b + prfixtry[pl]*switch0*switch2b + prfix[pl]*switch2*switch2b;
          if(DOENOFLUX != NOENOFLUX){
            ufix[pl] = ufixtryb[pl]*switch0b + ufixtry[pl]*switch0*switch2b + ufix[pl]*switch2*switch2b;
          }
        }

        //      dualfprintf(fail_file,"V[1]=%g ijk=%d %d %d switch0=%g switch2=%g\n",V[1],i,j,k,switch0,switch2);

      } // end if beyond some radius
    }

  }

}



/// hack to get rid of bad region at large distances when restarted
void debugfixup(void)
{
  int i,j,k;
  //    struct of_geom geomdontuse;
  //    struct of_geom *ptrgeom=&geomdontuse;
  FTYPE X[NDIM],V[NDIM];
  FTYPE *prfix,*ufix;
  int jjj;
  FULLLOOP{
    prfix=&GLOBALMACP0A1(pglobal,i,j,k,0);
    ufix=&GLOBALMACP0A1(unewglobal,i,j,k,0);

    // get geometry for center pre-interpolated values
    //get_geometry(i, j, k, CENT, ptrgeom);
    bl_coord_ijk_2(i,j,k,CENT,X, V) ;

    if(V[1]>300.0 && V[2]<0.075){

      prfix[RHO] = RHOMIN*pow(V[1],-2.0);

      prfix[UU]= MIN(prfix[RHO],prfix[UU]); // no more than u/rho=1
      prfix[URAD0] = MIN(MIN(prfix[RHO],prfix[URAD0]),prfix[UU]); // no more than Erf/rho=1 and Erf/u=1

      if(DOENOFLUX != NOENOFLUX){
        ufix[UU]=MAX(-prfix[UU],ufix[UU]);
        ufix[ENTROPY] = ufix[UU];
        ufix[ENTROPY] = MAX(0.0001,MIN(ufix[ENTROPY],1.0)); // like u/rho=1
        ufix[URAD0]=MAX(-prfix[URAD0],ufix[URAD0]);
      }

      SLOOPA(jjj) prfix[U1+jjj-1] = 0.0;
      SLOOPA(jjj) prfix[URAD1+jjj-1] = 0.0;

      if(DOENOFLUX != NOENOFLUX){
        SLOOPA(jjj) ufix[U1+jjj-1]= 0.0;
        SLOOPA(jjj) ufix[URAD1+jjj-1]=0.0;
      }
    }
  }


}

/// debug/fixup nonmad if regions going bad
void debugfixupnonmad(void)
{
  // hack to get rid of bad region at large distances when restarted
  int i,j,k;
  //    struct of_geom geomdontuse;
  //    struct of_geom *ptrgeom=&geomdontuse;
  FTYPE X[NDIM],V[NDIM];
  FTYPE *prfix,*ufix;
  int jjj;
  FULLLOOP{
    prfix=&GLOBALMACP0A1(pglobal,i,j,k,0);
    ufix=&GLOBALMACP0A1(unewglobal,i,j,k,0);

    // get geometry for center pre-interpolated values
    //get_geometry(i, j, k, CENT, ptrgeom);
    bl_coord_ijk_2(i,j,k,CENT,X, V) ;

    //    if(V[1]>300.0 && V[2]<0.075){
    //    if(V[1]>500.0 && V[2]<0.075){
    //if(V[1]>500.0 && V[2]>M_PI-0.08){
    //    if(V[1]>800.0 && V[2]>M_PI-0.08){
    //    if(V[1]>800.0 && V[2]>M_PI*0.5*1.1){
    if(V[1]>1E3 && V[2]>M_PI*0.5*1.1){
      
      prfix[RHO] = RHOMIN*pow(V[1],-2.0);

      prfix[UU]= MIN(prfix[RHO],prfix[UU]); // no more than u/rho=1
      if(DOENOFLUX != NOENOFLUX){
        ufix[UU]=MAX(-prfix[UU],ufix[UU]);
        ufix[ENTROPY] = ufix[UU];
        ufix[ENTROPY] = MAX(0.0001,MIN(ufix[ENTROPY],1.0)); // like u/rho=1
      }

      prfix[URAD0] = MIN(MIN(prfix[RHO],prfix[URAD0]),prfix[UU]); // no more than Erf/rho=1 and Erf/u=1
      if(DOENOFLUX != NOENOFLUX){
        ufix[URAD0]=MAX(-prfix[URAD0],ufix[URAD0]);
      }

      SLOOPA(jjj) prfix[U1+jjj-1] = 0.0;
      SLOOPA(jjj) prfix[URAD1+jjj-1] = 0.0;

      if(DOENOFLUX != NOENOFLUX){
        SLOOPA(jjj) ufix[U1+jjj-1]= 0.0;
        SLOOPA(jjj) ufix[URAD1+jjj-1]=0.0;
      }
    }
  }


}

/// debug/fixup mad if regions going bad
void debugfixupmad(void)
{
  // hack to get rid of bad region at large distances when restarted
  int i,j,k;
  struct of_geom geomdontuse;
  struct of_geom *ptrgeom=&geomdontuse;
  FTYPE X[NDIM],V[NDIM];
  FTYPE *prfix,*ufix;
  int jjj;
  FULLLOOP{
    prfix=&GLOBALMACP0A1(pglobal,i,j,k,0);
    ufix=&GLOBALMACP0A1(unewglobal,i,j,k,0);

    // get geometry for center pre-interpolated values
    get_geometry(i, j, k, CENT, ptrgeom);
    bl_coord_ijk_2(i,j,k,CENT,X, V) ;

    FTYPE bsq=0.0;
    bsq_calc(prfix,ptrgeom,&bsq);


    if(V[1]>60.0){
      limit_gamma(0,1.5,1.5,prfix,NULL,ptrgeom,-1);
    }

    if(V[1]>60.0 && bsq/prfix[RHO]>1.0){
      prfix[UU]= MIN(prfix[RHO],prfix[UU]); // no more than u/rho=1

      if(DOENOFLUX != NOENOFLUX){
        ufix[UU]=MAX(-prfix[UU],ufix[UU]);
        ufix[ENTROPY] = ufix[UU];
        ufix[ENTROPY] = MAX(0.0001,MIN(ufix[ENTROPY],1.0)); // like u/rho=1
      }

      prfix[URAD0] = MIN(MIN(prfix[RHO],prfix[URAD0]),prfix[UU]); // no more than Erf/rho=1 and Erf/u=1
      if(DOENOFLUX != NOENOFLUX){
        ufix[URAD0]=MAX(-prfix[URAD0],ufix[URAD0]);
      }

      limit_gamma(0,1.5,GAMMAMAXRAD,prfix,NULL,ptrgeom,-1);

    }

    if(V[1]>900.0 && (V[2]>M_PI*0.5*1.1 || V[2]<M_PI*0.5*0.9) ){
      
      prfix[RHO] = 1.5E-9*pow(V[1]/500.0,-1.5);

      prfix[UU]= MIN(prfix[RHO],prfix[UU]); // no more than u/rho=1
      if(DOENOFLUX != NOENOFLUX){
        ufix[UU]=MAX(-prfix[UU],ufix[UU]);
        ufix[ENTROPY] = ufix[UU];
        ufix[ENTROPY] = MAX(0.0001,MIN(ufix[ENTROPY],1.0)); // like u/rho=1
      }


      prfix[URAD0] = 1E-9*pow(V[1]/900.0,-1.0);
      prfix[URAD0] = MIN(MIN(prfix[RHO],prfix[URAD0]),prfix[UU]); // no more than Erf/rho=1 and Erf/u=1
      if(DOENOFLUX != NOENOFLUX){
        ufix[URAD0]=MAX(-prfix[URAD0],ufix[URAD0]);
      }

      limit_gamma(0,1.5,GAMMAMAXRAD,prfix,NULL,ptrgeom,-1);

    }
  }


}

/// debug/fixup nonmad if regions going bad
void debugfixupalt1(void)
{
  // hack to get rid of bad region at large distances when restarted
  int i,j,k;
  struct of_geom geomdontuse;
  struct of_geom *ptrgeom=&geomdontuse;
  FTYPE X[NDIM],V[NDIM];
  FTYPE *prfix,*ufix;
  int jjj;
  FULLLOOP{
    prfix=&GLOBALMACP0A1(pglobal,i,j,k,0);
    ufix=&GLOBALMACP0A1(unewglobal,i,j,k,0);

    // get geometry for center pre-interpolated values
    get_geometry(i, j, k, CENT, ptrgeom);
    bl_coord_ijk_2(i,j,k,CENT,X, V) ;

    FTYPE bsq=0.0;
    bsq_calc(prfix,ptrgeom,&bsq);

    if(0){
    if(V[1]>60.0){
      limit_gamma(0,1.5,GAMMAMAXRAD,prfix,NULL,ptrgeom,-1);

      prfix[UU]= MIN(prfix[RHO],prfix[UU]); // no more than u/rho=1
      if(DOENOFLUX != NOENOFLUX){
        ufix[UU]=MAX(-prfix[UU],ufix[UU]);
      }
    }
    }

    if(0){
    if(V[1]>60.0 && bsq/prfix[RHO]>1.0){
      prfix[UU]= MIN(prfix[RHO],prfix[UU]); // no more than u/rho=1

      if(DOENOFLUX != NOENOFLUX){
        ufix[UU]=MAX(-prfix[UU],ufix[UU]);
        ufix[ENTROPY] = ufix[UU];
        ufix[ENTROPY] = MAX(0.0001,MIN(ufix[ENTROPY],1.0)); // like u/rho=1
      }

      prfix[URAD0] = MIN(MIN(prfix[RHO],prfix[URAD0]),prfix[UU]); // no more than Erf/rho=1 and Erf/u=1
      if(DOENOFLUX != NOENOFLUX){
        ufix[URAD0]=MAX(-prfix[URAD0],ufix[URAD0]);
      }

      limit_gamma(0,1.5,GAMMAMAXRAD,prfix,NULL,ptrgeom,-1);

    }
    }
    if(0){
      //    if(V[1]>600.0 && (V[2]>M_PI*0.5*1.1 || V[2]<M_PI*0.5*0.9) ){
    if(V[1]>600.0 ){
      
      //prfix[RHO] = 1E-10*pow(V[1]/500.0,-1.5);

      prfix[UU]= MIN(prfix[RHO],prfix[UU]); // no more than u/rho=1
      if(DOENOFLUX != NOENOFLUX){
        ufix[UU]=MAX(-prfix[UU],ufix[UU]);
        ufix[ENTROPY] = ufix[UU];
        ufix[ENTROPY] = MAX(0.0001,MIN(ufix[ENTROPY],1.0)); // like u/rho=1
      }

      //prfix[URAD0] = 2E-10*pow(V[1]/500.0,-1.5);
      prfix[URAD0] = MIN(MIN(prfix[RHO],prfix[URAD0]),prfix[UU]); // no more than Erf/rho=1 and Erf/u=1
      if(DOENOFLUX != NOENOFLUX){
        ufix[URAD0]=MAX(-prfix[URAD0],ufix[URAD0]);
      }

      limit_gamma(0,1.5,GAMMAMAXRAD,prfix,NULL,ptrgeom,-1);

      if(DOENOFLUX != NOENOFLUX){
        if(ufix[U1]<0.0) ufix[U1]=0.0;
        ufix[U2]=ufix[U3]=0.0;
        if(ufix[URAD1]<0.0) ufix[URAD1]=0.0;
        ufix[URAD2]=ufix[URAD3]=0.0;
      }

    }
    }
  }


}


/// debug/fixup nonmad if regions going bad
void debugfixupaltdeath(void)
{
  // hack to get rid of bad region at large distances when restarted
  int i,j,k;
  struct of_geom geomdontuse;
  struct of_geom *ptrgeom=&geomdontuse;
  FTYPE X[NDIM],V[NDIM];
  FTYPE *prfix,*ufix;
  int jjj;
  FULLLOOP{
    prfix=&GLOBALMACP0A1(pglobal,i,j,k,0);
    ufix=&GLOBALMACP0A1(unewglobal,i,j,k,0);

    // get geometry for center pre-interpolated values
    get_geometry(i, j, k, CENT, ptrgeom);
    bl_coord_ijk_2(i,j,k,CENT,X, V) ;

    FTYPE bsq=0.0;
    bsq_calc(prfix,ptrgeom,&bsq);

    if(0){
    if(V[1]>60.0){
      limit_gamma(0,1.5,GAMMAMAXRAD,prfix,NULL,ptrgeom,-1);

      prfix[UU]= MIN(prfix[RHO],prfix[UU]); // no more than u/rho=1
      if(DOENOFLUX != NOENOFLUX){
        ufix[UU]=MAX(-prfix[UU],ufix[UU]);
      }
    }
    }

    if(0){
    if(V[1]>60.0 && bsq/prfix[RHO]>1.0){
      prfix[UU]= MIN(prfix[RHO],prfix[UU]); // no more than u/rho=1

      if(DOENOFLUX != NOENOFLUX){
        ufix[UU]=MAX(-prfix[UU],ufix[UU]);
        ufix[ENTROPY] = ufix[UU];
        ufix[ENTROPY] = MAX(0.0001,MIN(ufix[ENTROPY],1.0)); // like u/rho=1
      }

      prfix[URAD0] = MIN(MIN(prfix[RHO],prfix[URAD0]),prfix[UU]); // no more than Erf/rho=1 and Erf/u=1
      if(DOENOFLUX != NOENOFLUX){
        ufix[URAD0]=MAX(-prfix[URAD0],ufix[URAD0]);
      }

      limit_gamma(0,1.5,GAMMAMAXRAD,prfix,NULL,ptrgeom,-1);

    }
    }
    if(1){
      //    if(V[1]>600.0 && (V[2]>M_PI*0.5*1.1 || V[2]<M_PI*0.5*0.9) ){
    if(V[1]>1E3 ){
      
      //prfix[RHO] = 1E-10*pow(V[1]/500.0,-1.5);

      prfix[UU]= MIN(prfix[RHO],prfix[UU]); // no more than u/rho=1

      if(DOENOFLUX != NOENOFLUX){
        ufix[UU]=MAX(-prfix[UU],ufix[UU]);
        ufix[ENTROPY] = ufix[UU];
        ufix[ENTROPY] = MAX(0.0001,MIN(ufix[ENTROPY],1.0)); // like u/rho=1
      }

      //prfix[URAD0] = 2E-10*pow(V[1]/500.0,-1.5);
      prfix[URAD0] = MIN(MIN(prfix[RHO],prfix[URAD0]),prfix[UU]); // no more than Erf/rho=1 and Erf/u=1
      if(DOENOFLUX != NOENOFLUX){
        ufix[URAD0]=MAX(-prfix[URAD0],ufix[URAD0]);
      }

      //      limit_gamma(0,1.5,GAMMAMAXRAD,prfix,NULL,ptrgeom,-1);
      limit_gamma(0,6.0,GAMMAMAXRAD,prfix,NULL,ptrgeom,-1);

      if(DOENOFLUX != NOENOFLUX){
        if(ufix[U1]<0.0) ufix[U1]=0.0;
        //      ufix[U2]=ufix[U3]=0.0;
        
        if(ufix[URAD1]<0.0) ufix[URAD1]=0.0;
        //      ufix[URAD2]=ufix[URAD3]=0.0;
      }

    }
    }
  }


}

