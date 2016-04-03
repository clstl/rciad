#include <SFML/Graphics.hpp>
#include <iostream>

int main(int argc, char** argv){
    int nx = 800;
    int ny = 800;

    sf::RenderWindow window(sf::VideoMode(nx, ny), "SFML works!");
    sf::Image buffer;
    buffer.create(nx, ny, sf::Color::Black);

    
    for(int j = ny-1; j>=0; --j){
        for(int i = 0; i < nx; ++i){
            float r = float(i) / float(nx);
            float g = float(j) / float(ny);
            float b = 0.2f;

            int ir = int(255.99*r);
            int ig = int(255.99*g);
            int ib = int(255.99*b);

            buffer.setPixel(i, j, sf::Color(ir, ig, ib));
        }
    }

    sf::Texture buffer_texture;
    buffer_texture.loadFromImage(buffer);
    sf::Sprite sprite(buffer_texture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }
    

    return 0;
}
