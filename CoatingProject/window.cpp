#include <QString>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include "window.h"
#include "weather.h"

Window::Window(QWidget *parent) : QWidget(parent)
{

    //set the size of the window
    setFixedSize(1000,500);

    //LineEdit box
    //"this" keyword allows display on window
    textline = new QLineEdit(this);
    textline->setPlaceholderText("ZIP CODE");


    //create and position the button
    m_button = new QPushButton("Hello world", this);
    m_button->setGeometry(100,100,800,300);

    //add things to the button
    QFont font ("Courier", 20);
    QIcon icon ("/home/madeleine/Pictures/crocodile.jpg");
    m_button->setFont(font);
    m_button->setIcon(icon);
    m_button->setText("COAT?");
    m_button->setToolTip("A tooltip");

    //Do the connection: call slotButtonClicked when button is pressed
    connect(m_button, SIGNAL(clicked()), this, SLOT(slotButtonClicked()));

}

/* Executes when m_button is clicked
 *
 */
void Window::slotButtonClicked()
{
    zipcode= textline->text();
    m_button->setText(zipcode);
}
