/*
** EPITECH PROJECT, 2019
** Game.hpp
** File description:
** Game header
*/

#ifndef GAME_HPP
#define GAME_HPP

#define WINDOW_WIDTH 1536
#define WINDOW_HEIGHT 864

#include <SFML/Graphics.hpp>
#include "StateBuilder.hpp"
#include "StateStack.hpp"
#include "TcpStream.hpp"
#include "TcpListener.hpp"
#include "InputOptionsHandler.hpp"
#include "ClientPacketDispatcher.hpp"

class Game {
    public:
        Game(int ac, char **av);
        ~Game();

        void run();
    private:
        void loop();
        void displayHelp();
        void gameConnection();

        InputOptionsHandler m_input;
        ClientPacketDispatcher *m_dispatcher;
        StateBuilder m_stateBuilder;
        StateStack m_states;
        bool m_isRunning;
        std::shared_ptr<sf::RenderWindow> m_window;
};

#endif /* !GAME_HPP */
