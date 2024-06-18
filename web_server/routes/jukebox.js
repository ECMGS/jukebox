const express = require("express");

const router = express.Router();

const serialController = require("../controllers/serial");

router.get("/song", serialController.getSong,
                    (req, res) => {
                        res.json({ song: req.song });
                    }                
);

router.get("/next",     serialController.next,
                        (req, res) => {
                            res.json({ song: req.song });
                        }
);

router.get("/pause",    serialController.pause,
                        (req, res) => {
                            res.json({ song: req.song });
                        }
);

router.get("/play",     serialController.play,
                        (req, res) => {
                            res.json({ song: req.song });
                        }
);

module.exports = router;