

exports.index = (req, res, next) => {
    res.render("index", {ports: req.load.ports});
}

exports.getComport = (req, res, next) => {
    const comport = req.query.comport;

    if (comport == undefined || comport == null || comport == "") {
        res.redirect("/");
        return;
    }
    
    req.comport = comport;
    next();
}

exports.player = (req, res, next) => {
    res.render("player", {comport: req.comport});
}