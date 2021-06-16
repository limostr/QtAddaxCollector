pragma Singleton
import QtQuick 2.12
import "qrc:/font/js/all.min.js" as FontAwesome

Item {
    id : customFonts
    readonly property FontLoader fontAwesomeRegular: FontLoader {
        source: "qrc:/font/webfonts/fa-regular-400.ttf"
    }
    readonly property FontLoader fontAwesomeSolid: FontLoader {
        source: "qrc:/font/webfonts/fa-solid-900.ttf"
    }
    readonly property FontLoader fontAwesomeBrands: FontLoader {
        source: "qrc:/font/webfonts/fa-brands-400.ttf"
    }

    readonly property var names : {
        "fontAwesomeRegular" : customFonts.fontAwesomeRegular.name,
        "fontAwesomeSolid" : customFonts.fontAwesomeSolid.name,
        "fontAwesomeBrands" : customFonts.fontAwesomeBrands.name
    }
}

