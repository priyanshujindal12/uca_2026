const worker = new Worker("worker.js");

worker.postMessage("start");

worker.onmessage = function (event) {

    const usersDiv = document.getElementById("users");

    if (event.data.error) {
        usersDiv.innerHTML = `<p>${event.data.error}</p>`;
        return;
    }

    event.data.forEach(user => {
        usersDiv.innerHTML += `
            <p>${user.name} - ${user.status}</p>
        `;
    });
};