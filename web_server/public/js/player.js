let songHeader;

const updateSong = () => {
    songHeader = document.getElementById("song");

    fetch("/api/jukebox/song")
        .then((res) => res.json())
        .then((data) => {
            songHeader.innerText = data.song;
            console.log(data);
        });
}

const nextSong = () => {
    fetch("/api/jukebox/next")
        .then((res) => res.json())
        .then((data) => {
            songHeader.innerText = data.song;
            console.log(data);
        });
}

const pause = () => {
    fetch("/api/jukebox/pause")
        .then((res) => res.json())
        .then((data) => {
            songHeader.innerText = data.song;
            console.log(data);
        });
}

const play = () => {
    fetch("/api/jukebox/play")
        .then((res) => res.json())
        .then((data) => {
            songHeader.innerText = data.song;
            console.log(data);
        });

}

setInterval(updateSong, 100);