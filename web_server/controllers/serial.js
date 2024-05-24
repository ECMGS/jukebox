const { SerialPort } = require("serialport");

const uartTimeoutTime = 60; // MS

let song = "";
let commandSent = (data) => {};
let serial = null;
let uartBusy = false;

const songSetter = (rawData) => {
    const data = rawData.toString();
    if (data.includes("\n")) {
        console.log("lineJump");
        commandSent(song);
        song = "";
        return;
    }

    song += data;
    console.log(song);
};

const releaseUart = () => {
    uartBusy = false;
}

exports.list = (req, res, next) => {
    SerialPort.list().then((ports) => {
        req.load = { ports: ports, ...req.load };
        next();
    });
}

exports.connectSerial = (req, res, next) => {
    if (serial != null) { next(); return; }
    serial = new SerialPort({ path: req.comport, baudRate: 9600 });
    serial.on("data", songSetter);
    next();
}

exports.getSong = (req, res, next) => {  
    if (uartBusy) {
        req.song = song;
        next();
        return;
    }

    if (serial == null) {
        res.send("forbidden");
        return;
    }

    serial.write("info\n");
    commandSent = (song) => {
        req.song = song;
        next();
    };

    uartBusy = true;
    setTimeout(releaseUart, uartTimeoutTime);
}

exports.next = (req, res, next) => {
    if (serial == null) {
        res.send("forbidden");
        return;
    }

    serial.write("next\n");
    next();
}

exports.pause = (req, res, next) => {

    if (serial == null) {
        res.send("forbidden");
        return;
    }

    serial.write("pause\n");
    next();
}

exports.play = (req, res, next) => {

    if (serial == null) {
        res.send("forbidden");
        return;
    }

    serial.write("play\n");
    next();
}