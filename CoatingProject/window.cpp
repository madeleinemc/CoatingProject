#include <QString>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include "window.h"
#include "weather.h"

Window::Window(QWidget *parent) : QWidget(parent)
{
    //formatting
    setFixedSize(1000,500);
    //font
    font.setFamily("Helvetica");
    font.setPointSize(20);
    //background image
    QPixmap background ("://clouds.jpg");
    QPalette palette;
    palette.setBrush(QPalette::Background, background);
    this->setPalette(palette);

    //LineEdit box
    //"this" keyword allows display on window
    textline = new QLineEdit(this);
    textline->setPlaceholderText("ZIP CODE");
    textline->setMaxLength(5);
    textline->setFont(font);
    textline->move(10,10);

    //result
    result = new QLabel("No result yet", this); //might be useful to resize QLabel instead of making it long
    result->setFont(font);
    result->move(10,100);


    //create and position the button
    m_button = new QPushButton("COAT?", this);
    m_button->setGeometry(100,200,700,200);

    //add things to the button;
    m_button->setFont(font);
    m_button->setToolTip("Click for your clothing recommendation based on your local weather");

    //Do the connection: call slotButtonClicked when button is pressed
    connect(m_button, SIGNAL(clicked()), this, SLOT(slotButtonClicked()));


}

/* Executes when m_button is clicked
 *
 */
void Window::slotButtonClicked()
{
    // Get the information entered by the user
    zipcode = textline->text();


    Weather weather (zipcode);

    m_button->setText("COAT ME AGAIN");

    QString coat_text;
    switch(weather.get_coat()){
        case 0:
            coat_text = "NO COAT";
            break;
        case 1:
            coat_text = "LIGHT COAT";
            break;
        case 2:
            coat_text = "HEAVY COAT";
            break;
    }


    // Display the result of the weather analysis
    QFont bold_font (font);
    bold_font.setBold(true);
    result->setFont(bold_font);
    result -> setText(weather.get_loc() + ": " + coat_text);
    result->adjustSize();
}
