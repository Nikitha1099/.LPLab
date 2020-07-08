# Linux Programming Lab

This is a repository for programs in Linux Programming Lab. All the code is available in `workspace` directory. `Dockerfile` is available
in `docker` directory.

For instructions, regarding installation on docker (recommanded), follow the steps show below.

For instructions, regarding installation installation of Ubuntu on VirtualBox, see [VM_Install.md](https://github.com/SaiHemanthBR/.LPLab/blob/master/VM_Install.md)

## Requirements

  1. Docker Desktop.
  
  2. At least 1.5 GB of free storage on drive.
  
  3. A Good Internet Connection or some patience.

## Instructions to Install docker container.
  
  * Goto [Docker Website](https://www.docker.com/products/docker-desktop), download and install docker for your platform

  * Clone this Repo
    
    * Click the Download in the Upper right-hand corner

    * Or use this command
    ```
      git clone https://github.com/SaiHemanthBR/.LPLab.git
    ```
  
  * `cd` into this directory on terminal or command prompt
  
  *  On **macOS** or linux, run the the following commands:
  ```
    $ chmod +x build_docker.sh
    $ chmod +x run_docker.sh
  
    $ ./build_docker.sh
  ```

  * On **Windows**, run
  ```
    build_docker.bat
  ```

## To run docker container:

  * To run the containe, run the following command:
    * On **macOS**:
      ```
        $ ./run_docker.sh
      ```
    
    * On **Windows**:
      ```
        run_docker.bat
      ```
  
  * All code accessable in docker container resides in `workspace` directory. So save any code in `workspace` directory, to be able to run 
  in ubuntu
