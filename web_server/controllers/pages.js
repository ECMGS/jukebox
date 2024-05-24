

exports.index = (req, res, next) => {
    if (req.load.ports.length == 0) {
        req.load.ports = [{ path: "NULL", friendlyName: "No serial ports found" }];
    }
    res.render("index", {ports: req.load.ports});
}

exports.getComport = (req, res, next) => {
    const comport = req.query.comport;

    if (comport == undefined || comport == null || comport == "" || comport == "NULL") {
        res.redirect("/");
        return;
    }
    
    req.comport = comport;
    next();
}

exports.player = (req, res, next) => {
    res.render("player", {comport: req.comport});
}