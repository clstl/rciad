#include <iostream>

#include <SFML/Graphics.hpp>

#include "camera.hpp"
#include "Sphere.hpp"
#include "hitable_list.hpp"


math::vec3f random_in_unit_sphere() {
    math::vec3f p;
    do{
        p = math::vec3f(drand48(), drand48(), drand48())*2 - math::vec3f{1,1,1};
    }while(p.sq_length() >= 1.0);
    return p;
}

math::vec3f color(const math::Ray &r, geometry::Hitable *world) {
    geometry::HitRecord rec;
    if (world->hit(r, 0, MAXFLOAT, rec)) {
        math::vec3f target = rec.p + rec.normal + random_in_unit_sphere();
        return color(math::Ray(rec.p, target-rec.p), world)*0.5f;
    } else {
        math::vec3f unit_direction = r.direction().normal();
        float t = 0.5f * (unit_direction.y + 1.0f);
        return math::vec3f{1.0f, 1.0f, 1.0f} * (1.0f - t) + math::vec3f{0.5f, 0.7f, 1.0f} * t;
    }
}

sf::Color toColor(const math::vec3f vec) {
    auto c = vec * 255.99f;
    return {sf::Uint8(c.x), sf::Uint8(c.y), sf::Uint8(c.z)};
}

int main(int argc, char **argv) {
    int nx = 800;
    int ny = 600;
    int ns = 2;

    float ratio = ny / float(nx);

    sf::RenderWindow window(sf::VideoMode(nx, ny), "SFML works!");
    sf::Image buffer;
    buffer.create(nx, ny, sf::Color::Black);
    Camera cam{ratio};

    geometry::Hitable *list[2];
    list[0] = new geometry::Sphere({0, 0, -1}, 0.5f);
    list[1] = new geometry::Sphere({0, -100.5f, -1}, 100.0f);
    geometry::Hitable *world = new geometry::HitableList(list, 2);
    for (int j = 0; j < ny; ++j) {
        for (int i = 0; i < nx; ++i) {
            math::vec3f c{0, 0, 0};
            for (int s = 0; s < ns; s++) {
                float u = float(i + drand48()) / nx;
                float v = 1 - (float(j + drand48()) / ny);
                math::Ray r = cam.get_ray(u, v);
                c = c + color(r, world);


            }

           // std::cout << "Iteration: " << j*nx+i << " out of " << ny*nx << std::endl;

            c = c / float(ns);
            c = math::vec3f(sqrt(c.x),sqrt(c.y),sqrt(c.z));
            buffer.setPixel(i, j, toColor(c));
        }

    }

    sf::Texture buffer_texture;
    buffer_texture.
            loadFromImage(buffer);
    sf::Sprite sprite(buffer_texture);


    while (window.

            isOpen()

            ) {
        sf::Event event;
        while (window.
                pollEvent(event)
                ) {
            if (event.type == sf::Event::Closed
                || (event.type ==
                    sf::Event::KeyPressed
                    && event
                               .key.code == sf::Keyboard::Escape))
                window.

                        close();

        }

        window.clear();

        window.draw(sprite);
        window.display();

    }


    return 0;
}
