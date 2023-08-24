
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <QDebug>

#include "../qtGuiApplication/dbmanager.h"


using namespace testing;

TEST(dbmanager, dbmanagerTest)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}


TEST(testGetName, dbmanagerTest)
{
    qDebug() << "slayyyy";

    static const QString path = "parliament.db";

    DbManager db(path);

    QString name = "Jamie Strange";

    MP mp = db.getMpFromName(name);

    qDebug() << mp.getName();

    EXPECT_EQ(name, mp.getName());
}
