#include <QtCore>
#include <QtTest>

#include "../../include/Map.hpp"

#include "../../include/tools/Log.hpp"

#include <cstring>
#include <fstream>


const std::string pre_path = "../map_test/files/";


class MapTests : public QObject {

Q_OBJECT

private :

    std::ofstream *m_logFile;

public :

    MapTests() {

        m_logFile = new std::ofstream("logs.txt");
        Log::setOutput(*m_logFile);

        Log::v() << "-- Map, demo & test --";
    }


    ~MapTests() {
        m_logFile->close();
        delete m_logFile;
    }


private slots:

    /*
        Empty map test
    */
    void emptyMap() {

        se::Map m;
        QVERIFY(! m.isLoaded());
        QVERIFY(m.getName().empty());
        QVERIFY(m.getHeight() == 0);
        QVERIFY(m.getWidth() == 0);

        // dummy load
        m.load("unexisting_map.xml");

        // stay unloaded
        QVERIFY(! m.isLoaded());
        QVERIFY(m.getName().empty());
        QVERIFY(m.getHeight() == 0);
        QVERIFY(m.getWidth() == 0);
    }


    /*
        Getting content test
    */
    void realLoadingTest() {

        se::Map m(pre_path + "/map.xml");

        // map sould be loaded
        QVERIFY(m.isLoaded());

        // check attributes !
        QVERIFY(m.getName() == "Toxicity");
        QVERIFY(m.getHeight() == 600);
        QVERIFY(m.getWidth() == 800);

    }

};


QTEST_MAIN(MapTests)


