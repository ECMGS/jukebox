let songHeader;

const updateSong = () => {
    songHeader = document.getElementById("song");

    fetch("/api/jukebox/song")
        .then((res) => res.json())
        .then((data) => {
            if (data.song == "" || data.song.includes("ommand")) return;
            songHeader.innerText = data.song;
            console.log(data);
        });
}

const nextSong = () => {
    fetch("/api/jukebox/next").then(updateSong);
}

const pause = () => {
    fetch("/api/jukebox/pause").then(updateSong);
}

const play = () => {
    fetch("/api/jukebox/play").then(updateSong);
}

setInterval(updateSong, 500);