const express = require("express");

const path = require("path");

const pagesController = require("./controllers/pages");
const serialController = require("./controllers/serial");

const jukeboxRoutes = require("./routes/jukebox");

const app = express();

app.set("views", path.join(__dirname, "views"));
app.set('view engine', 'ejs');

app.use(express.json());
app.use(express.urlencoded({ extended: true }));

app.use('/static', express.static('public'));

app.use("/api/jukebox", jukeboxRoutes);

app.get("/",    serialController.list,
                pagesController.index
);

app.get("/player",          pagesController.getComport,
                            serialController.connectSerial,
                            pagesController.player
);

app.listen(3000, () => {
    console.log("listening on port 3000");
});