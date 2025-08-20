#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include<iostream>


int main(){

    sf::RenderWindow window(sf::VideoMode(800,600),"RPG Game 1");

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type ==sf::Event::Closed){ 
                window.close();
            }
            
        }


        window.clear();
        window.display();
    }


    

    return 0;
}


