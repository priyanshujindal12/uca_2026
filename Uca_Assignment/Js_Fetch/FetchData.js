const worker = new Worker("worker.js");
worker.postMessage("start");

worker.onmessage = function (event) {
    if (event.data.error) {
        console.error(event.data.error);
        return;
    }
    event.data.forEach(user => {
        console.log(`${user.name} - ${user.status}`);
    });
};