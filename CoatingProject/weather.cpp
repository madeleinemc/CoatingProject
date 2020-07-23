#include "weather.h"

Weather::Weather(QString new_zipcode)
{
    zipcode = new_zipcode;

    QUrl url = QUrl(QString("https://weather.com/weather/today/l/%1").arg(zipcode));

    QNetworkAccessManager manager;
    QNetworkReply *response = manager.get(QNetworkRequest(url));
    QEventLoop event;
    QObject::connect(response,SIGNAL(finished()),&event,SLOT(quit()));
    event.exec();
    html = response->readAll(); // Source should be stored here
}

QString Weather::view_html(){
    return html;
}
