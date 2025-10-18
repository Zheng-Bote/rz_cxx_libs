#include "database.hpp"

int Database::openSQLiteDatabase(const QString &pathToDbFile)
{
    db = new QSqlDatabase();
    *db = QSqlDatabase::addDatabase("QSQLITE");

    db->setDatabaseName(pathToDbFile);

    if (!db->open()) {
        qDebug() << "Error openDatabase:" << db->lastError().text();
        return 1;
    }
    return 0;
}

int Database::closeDatabase()
{
    //db->close();
    return 0;
}

int Database::executeQuery(const QString &queryString)
{
    QSqlQuery query(*db);
    if (!query.exec(queryString)) {
        qDebug() << "Error executeQuery:" << query.lastError().text();
        return 1;
    } else {
        while (query.next()) {
            qDebug() << "ID:" << query.value("id").toInt()
                     << "Name:" << query.value("name").toString()
                     << " Age: " << query.value("age").toInt();
        }
    }
    return 0;
}

int Database::executeQueryWithFields(const QString &queryString)
{
    QSqlQuery query(*db);
    if (!query.exec(queryString)) {
        qDebug() << "Error executeQuery:" << query.lastError().text();
        return 1;
    }
    QSqlRecord record = query.record();
    while (query.next()) {
        for (int i = 0; i < record.count(); i++) {
            QSqlField field = record.field(i);
            QString name = field.metaType().name();
            if (name.compare("int") == 0) {
                qDebug() << "Field name:" << field.name()
                         << "Value:" << query.value(field.name()).toInt();
            } else {
                qDebug() << "Field name:" << field.name()
                         << "Value:" << query.value(field.name()).toString();
            }

            qDebug() << "--------------------------------------";
        }
    }

    return 0;
}
