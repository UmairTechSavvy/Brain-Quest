
# Brain Quest : Challenge Your Intellect

## Overview

Brain Quest is a simple IQ Test Program designed using the core founding principles of Object-Oriented Programming (OOP). It allows users to test their mental abilities over a variety of different questioning categories along with additional fancy features. This program efficiently utilizes the features and concepts of OOP to provide a robust and engaging user experience.

## Features

- **Multiple Question Categories**: Test your IQ in various categories such as Mathematics, History,Sports and more.
- **OOP Principles**: Efficiently utilizes encapsulation, inheritance, polymorphism, and abstraction.
- **User-Friendly Interface**: Simple and interactive command-line interface.
- **Fancy Features**: Includes additional features to enhance user experience.

## Requirements

- Docker (installed and running)

## Usage

### Pulling and Running the Docker Image

1. **Pull the Docker Image**: Open your terminal and run the following command to pull the Docker image from Docker Hub:

    ```sh
    docker pull maaz9796/brainquest-image:v1
    ```

    This command will download the latest version of the Brain Quest Docker image to your local machine.

2. **Run the Docker Container**: Once the image is downloaded, you can run the Docker container using the following command:

    ```sh
    docker run --rm -it maaz9796/brainquest-image:v1
    ```

    - The `--rm` flag ensures that the container is removed after it stops running.
    - The `-it` flags combine `-i` (interactive) and `-t` (allocate a pseudo-TTY), allowing you to interact with the container's terminal.

3. **Use Brain Quest**: Follow the instructions provided by the program to navigate through the IQ test and enjoy the experience!

