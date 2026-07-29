# recvx-decomp

[![Build Status]][actions] [![Code Progress]][progress] [![Data Progress]][progress] 

[Build Status]: https://github.com/AshfordFamily/recvx-decomp/actions/workflows/progress.yml/badge.svg
[actions]: https://github.com/AshfordFamily/recvx-decomp/actions/workflows/progres.yml

[Code Progress]: https://decomp.dev/AshfordFamily/recvx-decomp.svg?mode=shield&label=Code&measure=matched_code_percent
[Data Progress]: https://decomp.dev/AshfordFamily/recvx-decomp.svg?mode=shield&label=Functions&measure=matched_functions
[progress]: https://decomp.dev/AshfordFamily/recvx-decomp

<img src="https://i.imgur.com/3Fl2QNQ.png"/> 

## About

> [!IMPORTANT]
Issues and pull-requests that are clearly **AI-generated** will be automatically **turned down**. Click [here](https://github.com/AshfordFamily/recvx-decomp/pull/40#issuecomment-4861213243) to read up on our stance in regards to the use of LLMs for contributions.

**recvx-decomp** is a reverse-engineering project for Resident Evil: Code Veronica X which has the goal of reconstructing the source code of the game by decompiling the MIPS in the PS2 ELF back to C. The project currently only works with the US release (**SLUS-20184**), with plans to add support for more regions in the future.

Currently, the engine and gameplay systems are decompiled, as well as the **CRI ADXT (Jan 26th, 2001)** lib employed by the game. Enemy AI and GFX code is still incomplete. Testing is done by repackaging the retail disc with our own compiled ELF using a script, and trying out the results on PCSX2. 

Groundwork has been made for decompiling the Dreamcast and GameCube releases of Code Veronica; see the Resources section on this page for some links. Once the project is completed, there will be many potential uses of the code, including and beyond porting.

## Building

The very first step should be to clone the repository: 
```
git clone --recursive https://github.com/AshfordFamily/recvx-decomp.git
```

Next you have to place your copy of the SLUS_201.84 file in the config folder. The setup now depends on whether you want to use a dev container or not.

### With Dev Container

If you're using an IDE that supports [dev containers](https://containers.dev/), such as Visual Studio Code, you can simply open the repository with as a dev container. 

You will need to have [Docker](https://www.docker.com/) or [Podman](https://podman.io/) installed and running on your machine to open a dev container.

### Without Dev Container

Requisites:
- Python
- MIPS Binutils
- wibo (if using Linux, for running Windows binaries)

Install splat with the following command: 
```
pip install -r config/requirements.txt
```

---

**Follow these instructions after entering the dev container or installing the requisites:**

Use the following command to setup objdiff:
```
python compile.py --setup
```

Either command should run without errors and generate an `objdiff.json` project file or a `config/asm` folder respectively.

From now on to build the project you just need to type the following command:
```
python compile.py
```

If you're using Linux, an installation of wibo is needed in order to run the Windows-only MWCC binary, 
a small prompt with install steps will be shown if the script can't find wibo in your path.

With the main.elf from compilation, you can repackage RE: CVX's ISO file with it to see the decompiled code in action. You need to put your copy of the game's DVD on the iso folder, and dump its contents with the following command:
```
python mkiso.py -m extract --iso iso/RE_CVX.iso
```

Then rebuild the disk with:
```
python mkiso.py -m insert
```

If successful, you will now see an ISO called "RECVX_NEW" in the iso folder that you can use to test the results with an emulator (preferrably PCSX2 for its debugging capabilities) or console.  

## Resources

Related decomp projects:
- [Resident Evil - Code: Veronica X (Nintendo GameCube)](https://github.com/fmil95/recvx-gc-decomp)
- [Resident Evil - Code: Veronica (Dreamcast)](https://github.com/fmil95/recv-dc-decomp)
- [Dino Stalker](https://github.com/fmil95/dinostalkRE)
- [Fahrenheit](https://github.com/fmil95/santamonica)
- [Fatal Frame](https://github.com/Mikompilation/Himuro)
- [Legacy of Kain: Soul Reaver](https://github.com/fmil95/soul-re)
- [Silent Hill](https://github.com/Vatuu/silent-hill-decomp)

AshfordFamily's org avatar fan art was designed by [fishiiarts_](https://www.instagram.com/fishiiarts_/).

## Disclaimer

recvx-decomp is licensed under **CC0 1.0 Universal**, which allows for commercial use of the project's code. However, for commercializing ports of the game to modern platforms we still very much recommend contacting Capcom first for a proper publishing deal. 
