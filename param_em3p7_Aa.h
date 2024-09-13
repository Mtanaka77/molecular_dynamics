!  param_em3p7_Aa.h
!
!  restart: numbr1 
!  EM parallel: num_proc
!
!    Give Lengthx in Angstrom, then is converted to cm !!
!
!     integer(C_INT) &
      integer*4 &
                 ns0,np0,nq0,kstart,kgrp,isizeX,isizeY,isizeZ, &
                 num_proc,lxy3,mx,my,mz,mza,mxyza, &
                 npq0,n00,n10,nbxc,nbxs,nbx2,nc3
!     real(C_DOUBLE) &
      real*8 &
                 sconv,Lenx3,Leny3,Lenz3,xmax3,ymax3,zmax3,    &
                 xmin3,ymin3,zmin3
      character  sname*6,cname*6,numbr1*2,numbr0*1
      logical    iflinx
! ----------------------------------------------------------
! #PBS -q small         # small24VH / medium 
! #PBS -l elapstim_req=00:15:00
! #PBS --venode=16      #  32
! #PBS --venum-lhost=8

      parameter  (iflinx=.false.,num_proc=16)      ! 600/8= 75
!       parameter  (iflinx=.false.,num_proc=96)    ! 768/96= 8 
!
      parameter  (sname='Cntemp',cname='cntemp')   ! cntemp
      parameter  (numbr1='Aa',numbr0='A')          ! .Aa
!
      parameter  (kstart=0,kgrp=1)
!       parameter  (kstart=1,kgrp=1)
!
!         particles:  nq0= np0 +e(-6):ns0/2 +e(-60/4):4*ns0/2
      parameter  (ns0=110600,np0=10120,nq0=np0+5*ns0/2)
!
      parameter  (isizeX=50,isizeY=50,isizeZ=128)  ! isizeX 10 Ang !
      parameter  (Lenx3=500.d0,Leny3=500.d0,Lenz3=1280.d0)
      parameter  (mx=201,my=201,mz=512)            ! Grid: 2.5 Ang, mz=512
      parameter  (mza=32)      ! test case -> 16)  ! mz=512, 32 ranks 
      parameter  (mxyza=mx*my*mza)                 ! divided in Z
!
!     parameter  (isizeX=50,isizeY=50,isizeZ=192)  ! isizeX 10 Ang !
!     parameter  (Lenx3=500.d0,Leny3=500.d0,Lenz3=1920.d0)
!     parameter  (mx=201,my=201,mz=768)            ! Grid: 2.5 Ang, mz=768
!     parameter  (mza=8)                           ! mz=768, 96 ranks
!     parameter  (mxyza=mx*my*mza)
! ----------------------------------------------------------
      parameter  (lxy3= 3*mx*my)
      parameter  (sconv=1.0d-8)
!
      parameter  (npq0=ns0+np0+nq0)
      parameter  (n00=npq0/num_proc+1,n10=ns0/num_proc+1)
!     parameter  (nbxs=7000,nbxc=5000,nbx2=5000)
      parameter  (nbxs=6000,nbxc=3500,nbx2=3500)   ! medium ?
!     parameter  (nbxs=3500,nbxc=2000,nbx2=2000)   ! small in 96 cpu
      parameter  (nc3=isizeX*isizeY*isizeZ)
!
! zero at ymin3< 0 <ymax3
!  E*B direction is -y
!  parameter  (mx=201,my=201,mz=608)            ! Grid: 2.5 Ang, mz=600
      parameter  (xmax3= (100/200.d0)*sconv*Lenx3, & ! EM field 200*400 meshes
                  xmin3=-(100/200.d0)*sconv*Lenx3, & ! 
                  ymax3= (100/200.d0)*sconv*Leny3, & !  E*H field
                  ymin3=-(100/200.d0)*sconv*Leny3, & ! 
                  zmax3= (256/512.d0)*sconv*Lenz3, & !  axial direction 
                  zmin3=-(256/512.d0)*sconv*Lenz3)   ! 
!                   zmax3= (384/768.d0)*sconv*Lenz3, & !  axial direction 
!                   zmin3=-(384/768.d0)*sconv*Lenz3)   ! 
!
!  /data/sht/tanakam/cntemp + .06a
!  /home/tanakam/cntem3/Cntemp + _config.START + A
      character  praefixs*27,praefixc*24,praefixe*24,    &
                 praefixi*24,suffix1*2,suffix0*1
      common/filname/ praefixs,praefixc,praefixe,        &
                      suffix1,suffix0
      common/filnam2/ praefixi
! ---------------------------------------------
