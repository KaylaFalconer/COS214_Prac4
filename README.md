# COS214_Prac4
# Commands to reproduce build and exeute the program
# 1. Build the Docker image (using the Dockerfile)
 docker build -t taskforge-image . --no-cache


# 2. Run the program
docker run --rm taskforge-image

# 3. Run Valgrind
docker run --rm taskforge-image valgrind --leak-check=full ./taskforge

# 4. Run GDB
docker run --rm -it taskforge-image gdb ./taskforge