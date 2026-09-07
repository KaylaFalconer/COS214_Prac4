# Use Ubuntu as the base environment
FROM ubuntu:22.04

# Stop Ubuntu from asking for timezone/location input during install
ENV DEBIAN_FRONTEND=noninteractive

# Install the exact tools required(g++, make, gdb, valgrind)
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
    build-essential \
    g++ \
    make \
    gdb \
    valgrind \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Set the working directory inside the container
WORKDIR /app

# Copy everything from the local project into the container's /app folder
COPY . .

# Compile the program inside the container
RUN make clean && make

# The command to run when the container starts
CMD ["./taskforge"]
