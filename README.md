Relativistic and Electromagnetic Molecular Dynamics Simulation for Nano-Scale Phenomena

A molecular dynamics simulation code has been created for relativistic and electromagnetic fields in three dimensions, and is used such as nanoscale particle phenomena. Maxwell equations are solved, and the momentum equations of relativistic particles are then advanced in time. But, it is noted that the Gauss's equation must be corrected as finite errors accumulate in the divergence term. This is true if a discrete coordinate scheme in any method is utilized.

All explicit simulation code must satisfy the Courant condition, that is, Dx(length)/Dt(time step) > c, the speed of light. 
Four physical CGS units are used in this code: a_unit= 1.00d-08 cm, t_unit= 1.00d-15 sec, electron mass m_unit= 0.9110d-27 g and its charge e_unit= 4.8032d-10 esu. The mass of hydrogen, for example, is 1.6726d-24 g. One needs files in the simulation: 1) @cnt3-3p8Ca.f03: Molecular dynamics simulation code, 2) param_em3p8_Ca.h: Common parameters of this simulation, 3) Cntemp_config.STARTC: figure parameters, 4) p_config_ss.xyz_D150 and P135: 4) Pellet electrons, H, C and Au ions. The program is written in Fortran 2003 and MPI version 3 for parallelization.

A simulation of the nanotube accelerator is set up by putting pellets of H, C and Au atoms and associated electrons at null velocity. 
Electromagnetic monochromatic waves at the wavelength 800 nm are travelling from the negative direction toward the origin and then go out to the positive direction. The pellets at the origin are irradiated by these waves and are ejected to ion perpenducular and electron parallel directions toward an open space. The final energies for laser intensity 10^22 W/cm^2 are around 30-40 MeV in 20-40 fs, which is shown by animation movies at my homepage. 

To analize simulation results, some programs are provided here as post processing. They are @3dfdisp.f and
@3ddisp.f03, as examples, for which the velocity distributions in parallel and perperdicular directions
are plotted in time and the time sequential plots of ions and electrons. 
They are discussed in the latter half of the CPC paper in 2019 (Ref. 1 below).

The parallel simulation code is designed for now the one-dimensional case (the z-direction) where the long axis of pellets is open to eject heavy ions in that derection. 
Finally, the machine run time depends on the physical time and cpu's architecture. For the elapsed time of parallel simulation it executed in 3.2 sec/step for 52 ranks and 4.0 10^5 particles (equal to 1 fs for elapsed 1.8 hours) by Fujitsu FX100 Supercomputer.  


References:

1. M. Tanaka and M. Murakami, Relativistic and electromagnetic molecular dynamics simulations for a carbon-gold nanotube accelerator, Computer Physics Communications, 241, 56-63 (2019).

2. M. Tanaka, A simulation of low-frequency electromagnetic phenomena in kinetic plasmas of three dimensions, J.Comput. Phys., 107, 124-145 (1993).

3. M. Murakami and M. Tanaka, Generation of high-quality mega-electron volt proton beams with intense-laser-driven nanotube accelerator, Applied Phys. Letters, 102, 163101 (2013).

