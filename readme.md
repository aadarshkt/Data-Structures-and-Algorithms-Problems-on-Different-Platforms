<!-- To view this document, open this in VSCODE and press CTRL+SHIFT+V -->

# Objective

To run a HelloWorld C++ source file that prints timestamps with VEOS-QEMU.

## Steps

1. **Download the Required File**

   - Download `IntegrateDockerDemo.tar.gz`.

2. **Modify the Dockerfile**

   - Replace the following lines:
     ```Dockerfile
     # FROM ds-pe-veos-docker.bas-common.dspace.de/library/ubuntu:jammy-20231004
     FROM hexpm/elixir:1.16.0-erlang-26.2.1-ubuntu-jammy-20231004
     ```

3. **Edit `README.sh` File**

   - Add the following line at the start:
     ```bash
     cp -r ./* /tmp/
     ```
   - Comment out around line 35:
     ```bash
     # docker run --rm -it ubuntu-base-amd64
     ```
   - Change the command around lines 57, 102, and 131:
     ```bash
     # mkfs.ext4 -E lazy_itable_init=0,lazy_journal_init=0 -G4096 -m0 Ubuntu_x86_64.raw 600m
     mkfs.ext4 -E lazy_itable_init=0,lazy_journal_init=0 -G4096 -m0 Ubuntu_x86_64.raw 1G
     ```
   - Uncomment the QEMU starting command around lines 73, 85, 120, 159, and 238:
     ```bash
     # qemu-system-x86_64 -nodefaults -nographic -no-reboot "-smp" "1" -serial "stdio" -m \
     "256" -drive "if=virtio,file=Ubuntu_x86_64.raw,format=raw" -nic user,model=virtio
     ```
   - Modify the command around line 170:
     ```bash
     # sudo apt install -y veos-qemu/*.deb
     sudo apt install -y ./veos-qemu/*.deb
     ```

4. **Finalize `README.sh` Changes**

   - The changes to the `README.sh` file are now complete.

5. **Import the JSON File**

   - Import the JSON file into the `.osa` file located at `/tmp`.

6. **Start the Simulation**

   - In another terminal tab, execute the following commands:
     ```bash
     cd /tmp
     export PATH=/opt/dspace/veos2024a/bin:$PATH
     veos-sim unload
     veos-sim load -s Ubuntu_x86_64.osa
     ```
   - Ensure that licenses are available to run the simulation.

7. **Check Simulation Logs**
   - Verify the logs in the previous terminal tab.
   - Alternatively, in a new terminal tab:
     ```bash
     cd /tmp
     tail -f Ubuntu_x86_64.out
     ```

## How to Check for TAP Device and Connect to QEMU via SSH

1. Check if a TAP device is present on the Linux host:
   ```bash
   ip link show
   ```
2. If the TAP device is available, configure and connect via SSH:
   ```bash
   sudo ip link set <your-tap-interface-name> up \
   && sudo ip addr add <tap-interface-in-same-subnet-as-QEMU> dev <your-tap-interface-name> \
   && sudo sysctl -w net.ipv4.ip_forward=1
   ```
   Example
   ```bash
    sudo ip link set tap0 up \
    && sudo ip addr add 192.168.7.1/24 dev tap0 \
    && sudo sysctl -w net.ipv4.ip_forward=1
   ```
