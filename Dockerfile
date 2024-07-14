# Use an appropriate base image for your C++ application
FROM gcc:latest

# Set the working directory inside the container
WORKDIR /app

# Create a directory for BrainQuest
RUN mkdir -p /app/BrainQuest

# Copy the entire "BrainQuest (Semester Project)" directory into the container
COPY ["BrainQuest (Semester Project)", "/app/BrainQuest/"]

# Change to the Source Files directory
WORKDIR /app/BrainQuest/Source Files

# Compile the C++ code (assuming main.cpp is in this directory)
RUN g++ -o main main.cpp

# Set the command to run your executable when the container starts
CMD ["./main"]
