#include "user.h"

User::User(const QString &name, int age, QObject *parent)
    : m_age(age), m_name(name), QObject{parent}
{}

QString User::getName() const
{
    return m_name;
}

void User::setName(const QString &name)
{
    m_name = name;
}

int User::getAge() const
{
    return m_age;
}

void User::setAge(int age)
{
    m_age = age;
}
