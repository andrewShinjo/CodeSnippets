#ifndef USER_H
#define USER_H

#include <QObject>

class User : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(int age READ getAge WRITE setAge NOTIFY ageChanged)

public:
    User(const QString &name, int age, QObject *parent = nullptr);
    QString getName() const;
    void setName(const QString &name);
    int getAge() const;
    void setAge(int age);

signals:

    void nameChanged();
    void ageChanged();

private:

    QString m_name;
    int m_age;
};

#endif // USER_H
