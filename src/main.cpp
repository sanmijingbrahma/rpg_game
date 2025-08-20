#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <string>


int main(){
    //Create Window
    sf::RenderWindow window(sf::VideoMode(800,600),"RPG Game 1");

    
    //Create Rectangle
    sf::RectangleShape map(sf::Vector2f(400.f,300.f));
    map.setPosition(200.f,150.f);
    map.setFillColor(sf::Color::Green);
   

    sf::Font font;
    if(!font.loadFromFile("../assets/fonts/dragon.ttf")){
        return 1;
    }

    sf::Text fpsText;
    fpsText.setFont(font);
    fpsText.setCharacterSize(20);
    fpsText.setFillColor(sf::Color::White);
    fpsText.setPosition(10.f,10.f);


    sf::Clock clock;
    float lastTime = 0.f;



 



    //Game loop
    while(window.isOpen()){
        //handle Events
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type ==sf::Event::Closed){ 
                window.close();
            }
            
        }
        
        // Update
        float currentTime = clock.getElapsedTime().asSeconds();
        float fps = 1.f/(currentTime - lastTime);
        lastTime = currentTime;
        fpsText.setString("FPS : "+std::to_string(static_cast<int>(fps)));
        
        //Clear window
        window.clear();

        //Draw
        window.draw(map);
        window.draw(fpsText);

        //display
        window.display();
    }


    

    return 0;
}


