#include <SFML/Graphics.hpp>


int main(){
    //creamos la ventana
    sf::RenderWindow ventana(sf::VideoMode(320,240), "@Pelota");

    //sincronizamos la frecuencia con la ventan del monitor
   // ventana.setVerticalSyncEnable(true);

    int limite_izq = 0, limite_der = 320, limite_sup = 1, limite_inf = 240;
    int x_cir = 10, y_cir = 10, x_rec = 135, y_rec = 230;
    int incremento_x_cir = 1, incremento_y_cir = 1; //velocidad del circulo
    int incremento_x_rec = 15; //velocidad de triangulo
    int largo_barra = 50, altura_barra = 10;
    int radio_cir =10;

    //definimos un circulo de radio 10
    sf::CircleShape circulo1(radio_cir);
    //definimoes el rectangulo
    sf::RectangleShape barra(sf::Vector2f(largo_barra, altura_barra));

    //ejecutar el programa mientras la ventana esta abierta
    while(ventana.isOpen())
    {
        //verificamos todos los eventos de la ventan
        sf::Event evento;
        while(ventana.pollEvent(evento)){
            //"cierre solicitado" evento: cerramos la ventana
            if(evento.type == sf::Event::Closed)
                ventana.close();

            if(sf::keyboard::isKeypressed(sf::KeyBoard::Right)){
                if(x_rec <= limite_der - largo_barra){
                    x_rec = x_rec + incremento_x_rec;
                }
            }
            if(sf::Keyboard::isKeypressed(sf::Keyboard::Left)){
                if(x_rec >= limite_izq){
                    x_rec = x_rec - incremento_x_rec;
                }
            }

        }
        //limpiamos la ventan con color negro
        ventana.clear(sf::Color::Black);

        //verificamos los bordes de la ventana y cambiamos
        //el signo del incremento de x_cir,ycir
        if(x_cir <= limite_izq){
            incremento_x_cir = -1*(incremento_x_cir);
        }

        if(x_cir >= limite_der - (radio_cir*2)){
            incremento_x_cir = -incremento_x_cir;
        }

        if(y_cir <= limite_sup){
            incremento_y_cir = -1*(incremento_y_cir);
        }

        if(y_cir >= limite_inf - (radio_cir*2)){//en el vacio
            x_cir =10, y_cir=10;
        }

        x_cir = x_cir + incremento_x_cir;
        y_cir = y_cir + incremento_y_cir;

        //pasamos las nuevas cordenadas al objeto del circulo1

        circulo1.setPosition(x_cir,y_cir);
        barra.setPosition(x_rec,y_rec);

        sf::FloatRect circulo1Box = circulo1.getGlobalBounds();
        sf::FloatRect barraBox = barra.getGlobalBounds();

        if(circulo1box.intersects(barrabox)){//colision
            incremento_y_cir = -1*incremento_y_cir;
        }

        ventana.draw(circulo1); //dibujamos el circulo en la ventana
        ventana.draw(barra); //dibujamos la barra en la ventana

        //mostramos la ventana
        ventana.display();

    }

    return 0;
}


