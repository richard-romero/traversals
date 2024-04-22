#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include "graph.h"
using namespace::std;
//#define x_max 1840
//#define y_max 1000
#define x_max 40
#define y_max 30

#define multiplier 14
#define vertex_radius 6.5
#define private public

// a utility function to draw lines with SFML
void draw_line(pair<int, int> p1, pair<int, int> p2, sf::Color color, sf::Window& window) {
    //this is a basic test of functionality



};

int main() {
    Graph* my_graph = new Graph();
    
    // opens the window at 1840x1000 resolution with the title "Traversals"
    sf::RenderWindow window(sf::VideoMode(1840, 1000), "Traversals");

    // have the window display a 'View' rather than the raw objects
    // this is like having a movable camera show what's being rendered
    // and offers much better flexibility for things like zooming in 
    // and moving around
    sf::View view({0, 0}, {x_max*multiplier, y_max*multiplier});
    window.setView(view);

    // default SFML example circle, left in as a nice marking for where
    // the center of the view is
    sf::CircleShape shape(10.f);
    shape.setFillColor(sf::Color::Green);

     
    //this block may be useful for testing.
    int sum = 0;
    for (auto p: my_graph->vertices) {
        sum += p.second.size();
    }
    cout << "Num of edges: " << (sum/2) << endl;
    cout << "Num of vertices: " << my_graph->vertices.size() << endl;
    /**/

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            // listen for keypresses and do certain things
            // when certain keys are pressed
            if(event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                    cout << "A*" << endl;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                    cout << "Dijkstra's Algorithm" << endl;

                }
            }
            else if(event.type == sf::Event::Closed) {
                window.close();
            }          
        }

        window.clear();
        window.draw(shape);

        // very bad and very slow and very temporary way to draw every vertex
        // (redraws every frame unnecessarily)
        for(auto p: my_graph->vertices) {
            
            // draw vertices
            sf::CircleShape temp(vertex_radius, 20);
            temp.setPosition(p.first.first*multiplier, p.first.second*multiplier);
            window.draw(temp);

            //draw edges (TODO)
        }

        window.display();
    }
    return 0;
}

