# Linux Programming Lab

This is a repository for programs in Linux Programming Lab. All the code is available in `workspace` directory. `Dockerfile` is available
in `docker` directory.

For instructions, regarding installation on docker (recommanded), follow the steps show below.

For instructions, regarging installation installation of Ubuntu on VirtualBox, see [VM_Install.md](https://github.com/SaiHemanthBR/.LPLab/blob/master/VM_Install.md)

## Requirements

  1. Docker Desktop.
  
  2. At least 7 GB of free storage on Drive.
  
  3. A Good Internet Connection or some patience.

## Instructions to Install docker container.
  
  1. Go-To [Docker Website](https://www.docker.com/products/docker-desktop), download and install docker for your platform

  2. Clone this Repo
     
    * Click the Download in the Upper right-hand corner

    * Or use this command
      ```
      git clone https://github.com/SaiHemanthBR/.LPLab.git
      ```
  
  4. `cd` into this directory on terminal or command prompt
  
  3. On macOS or linux, run the the following commands:
    ```
      $ chmod +x build_docker.sh
      $ chmod +x run_docker.sh
      
      $ ./build_docker.sh
    ```

## To run docker container:

  * To run the containe, run the following command:
    ```
      $ ./run_docker.sh
    ```
  
  * All code accessable in docker container resides in `workspace` directory. So save any code in `workspace` directory, to be able to run 
  in ubuntu