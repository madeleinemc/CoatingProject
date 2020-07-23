#ifndef WINDOW_H
#define WINDOW_H

#include <QString>
#include <QWidget>
#include <QLineEdit>
#include <QUrl>

class QPushButton;
class QLineEdit;
class Window : public QWidget
{

    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);

public slots:
    void slotButtonClicked();

private:
    QPushButton *m_button;
    QLineEdit *textline;
    QString zipcode;
};

#endif // WINDOW_H
