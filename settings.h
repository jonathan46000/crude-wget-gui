#ifndef SETTINGS_H
#define SETTINGS_H
#include <QObject>
#include <QString>

class Settings : public QObject
{
    Q_OBJECT

private:
    QString default_directory;
    QString settings_directory;
    QString settings_file;

public:
    explicit Settings(QObject *parent = 0);
    QString get_default_directory(void);

signals:

public slots:
    void set_default_directory(QString in_string);
};

#endif // SETTINGS_H
