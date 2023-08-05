# capy adventure

tired of being a human? live and breath a capybara's life in this amazing game capy adventure
the objective is the same as the everyday routine of a capybara  grab all the guaranás and after that go for a swim!

this game was made interely in C using my own custom made functions only using write malloc and free
i also used minilibx (mlx_linux) for the graphics

HOW TO COMPILE THE GAME (linux/macOS)

1 - install the packages necessary to compile the game (copy this line)
    sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev

2 - compile all the project (copy this line)
    cd mlx_linux && make && cd ..
    make re

3 - run the executable file (copy this line)
    ./capy_adventure map.ber

4 - If you want to change the map
    the .ber file it works like an .txt file each map must have a P and a E and at least a C
    you can alter it the program will run only if the map is valid (it will check the map)

    1 -> WALL
    0 -> EMPTY PLOT
    P -> PLAYER
    E -> EXIT
    C -> COLLECTIBLE

here is an example of a valid map (it has to be .ber file) :


![image](https://github.com/SebastiaoJeronimo/so_long/assets/99453107/ab708900-892b-4ea3-98b8-a6deae3a6674)


EXAMPLE OF THE GAME:
![image](https://github.com/SebastiaoJeronimo/so_long/assets/99453107/54f67897-1a04-42e2-8c34-47090a72ace3)
