function checkRegistration() {
    var registrationInput = document.getElementById("registrationInput").value;
    var result = document.getElementById("result");

    if (registrationInput.toLowerCase() === "да") {
        result.innerHTML = "Круто!";
    } else {
        result.innerHTML = "Попробуй ещё раз";
    }

    return false;
}
var login = prompt("Enter Login: ");

if (login === "admin") {
    var password = prompt("Enter password: ");

    if (password === "admin") {
        alert("Hello!");
    } else if (password === null || password === "") {
        alert("denied");
    } else {
        alert("Wrong password");
    }
} else if (login === null || login === "") {
    alert("denied");
} else {
    alert("i dunno u");
}



document.querySelector("#like_button").onclick = function () {
    if (like_button.style.color == 'white') {
        like_button.style.color = 'red';

            const heart = document.querySelector(".love");
            heart.addEventListener("mousemove", (event) => {
            const xPos = event.offsetX;
            const yPos = event.offsetY;
            const spanEl = document.createElement("span");
            spanEl.style.left = xPos + "px";
            spanEl.style.top = yPos + "px";
            heart.appendChild(spanEl);

            if (like_button.style.color == 'red') {
                spanEl.style.visibility = "visible";
            } else {
                spanEl.style.visibility = "hidden";
            }
        });

    } else {
        like_button.style.color = 'white';
    }
};
