# C-SKY Toolchain and Xboot Build Setup

This directory contains scripts to download and install the C-SKY toolchain and build the `xboot` project for the `gx6605s` target.

## Instructions

### 1. Set Up the Toolchain

First, you need to download and install the C-SKY toolchain.

*   **Run the setup script:**
    ```bash
    ../setup_csky_toolchain.sh
    ```
    This script will download and extract the toolchain to `/opt/csky-elf-tools`. It will ask for your `sudo` password to create the directory.

*   **Add the toolchain to your PATH:**
    After the installation is complete, you will need to add the toolchain's `bin` directory to your system's `PATH` to use it. You can do this by adding the following line to your shell's configuration file (e.g., `~/.bashrc`, `~/.zshrc`):
    ```bash
    export PATH=$PATH:/opt/csky-elf-tools/bin
    ```
    You will need to restart your shell or source the configuration file for the changes to take effect.

### 2. Build Xboot

Once the toolchain is installed and in your `PATH`, you can build the `xboot` project.

*   **Run the build script:**
    ```bash
    ../build_xboot.sh
    ```
    This script will configure the build environment and compile the `xboot` project. The resulting binaries will be placed in the `output/` directory.

### 3. Verify the Build

To verify that the build was successful, you can check the file type of the `xboot` binary:
```bash
file ../output/xboot
```
It should be identified as a `C-SKY` executable.
