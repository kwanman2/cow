
/*! \file superdecs.rad.h
    \brief Large arrays for Koral/RADIATION
*/

/*! \file superdecs.rad.h
    \brief AUTOGENERATED from superdecs.rad.h
*/

#if(EOMRADTYPE!=EOMRADNONE && STORETLAB2ORTHO==1)
extern FTYPE BASEMETMACP2A2(tlab2ortho,BOOSTGRIDPOS,BOOSTDIRS,N1M+SHIFT1,N2M+SHIFT2,N3M+SHIFT3,NDIM,NDIM);
#endif


#if(EOMRADTYPE!=EOMRADNONE)
extern int BASEMACP0A1(prioritermethod,N1M+SHIFT1,N2M+SHIFT2,N3M+SHIFT3,NUMPRIORITERMETHODINDEX);
#endif


#if(EOMRADTYPE!=EOMRADNONE)
extern FTYPE BASEMACP1A1(Mradk,MAXTIMEORDER,N1M,N2M,N3M,NPR);
// Mradk[MAXTIMEORDER] to sore M^i from M^0, M^1, etc.
// IMEX requires storing all stages for each stage.
#endif
