pragma Singleton
import QtQuick 2.12
import "../AddaxCollectorMonitoring/font/js/all.min.js" as FontAwesome

Item {
    id : customFonts
    readonly property FontLoader fontAwesomeRegular: FontLoader {
        source: "qrc:///font/webfonts/fontawesome-free-5.7.2-web/fa-regular-400.ttf"
    }
    readonly property FontLoader fontAwesomeSolid: FontLoader {
        source: "qrc:///font/webfonts/fontawesome-free-5.7.2-web/fa-solid-900.ttf"
    }
    readonly property FontLoader fontAwesomeBrands: FontLoader {
        source: "qrc:///font/webfonts/fontawesome-free-5.7.2-web/fa-brands-400.ttf"
    }

    readonly property var names : {
        "fontAwesomeRegular" : customFonts.fontAwesomeRegular.name,
        "fontAwesomeSolid" : customFonts.fontAwesomeSolid.name,
        "fontAwesomeBrands" : customFonts.fontAwesomeBrands.name
    }
}
