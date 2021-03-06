#ifndef WINDOW_H
#define WINDOW_H

#include <QString>
#include <QWidget>
#include <QLineEdit>
#include <QUrl>
#include <QLabel>

class QPushButton;
class QLineEdit;
class Window : public QWidget
{

    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);

public slots:
    void slotButtonClicked();
    void slotresizeResult();

signals:
    void resultChanged();

private:
    QPushButton *m_button;
    QLineEdit *textline;
    QString zipcode;
    QLabel *result;
    QFont font;

    bool check_zip();
};

#endif // WINDOW_H
