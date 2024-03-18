var captcha;
function generate() {
    document.getElementById("submit").value = "";
    captcha = document.getElementById("image");
    var uniquechar = "";

    const randomchar =
"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    for (let i = 1; i < 5; i++) {
        uniquechar += randomchar.charAt(
            Math.random() * randomchar.length)
    }

    captcha.innerHTML = uniquechar;
}
function checkEmpty() {
    if (!document.getElementById("submit").value)
{
    alert('empty enter');
}
}
function printmsg() {
    var sh_h = document.getElementById('check-c');
    var firstCaptcha=document.getElementById('image');
    var firstCaptchainput=document.getElementById('user-input');
    var firstCaptchaBTN=document.getElementById('btn');
    var LoginBTN=document.getElementById('login-btn');


    const usr_input = document
        .getElementById("submit").value;
    if (!document.getElementById("submit").value)
    {
        alert('empty enter');
    }
while (true) {
    if (usr_input == captcha.innerHTML) {
        var s = document.getElementById("key")
            .innerHTML = "!";
        generate();
    LoginBTN.style.opacity = "1";
    LoginBTN.style.cursor = "pointer";
        return false;
    }
    else if(usr_input != captcha.innerHTML){
        var s = document.getElementById("key")
        sh_h.classList.add('show-block');
        firstCaptcha.classList.add('remove-block')
        firstCaptchainput.classList.add('remove-block')
        firstCaptchaBTN.classList.add('remove-block')
        return false;
    }
    else {
        var s = document.getElementById("key")
        generate();
        return false;
    }
}

}


function Accumulator(startingValue) {
    this.value = startingValue;

    this.read = function() {
        var input = prompt("Enter a number:");
        var number = parseFloat(input);
        if (!isNaN(number)) {
            this.value += number;
            document.getElementById('current-value').textContent = this.value;
        } else {
            alert("Invalid input. Please enter a valid number.");
        }
    };
}

var startingValue = 0; // Example starting value
var accumulator = new Accumulator(startingValue);

document.getElementById('starting-value').textContent = startingValue;

document.getElementById('read-btn').addEventListener('click', function() {
    accumulator.read();
});



function truncate(str, maxlength) {
    if (str.length > maxlength) {
        return str.slice(0, maxlength - 1) + "…";
    } else {
        return str;
    }
}


var originalString = "This is a very long text that needs to be truncated.";
var maxLength = 20;
var truncatedString = truncate(originalString, maxLength);
console.log(truncatedString); // Output: "This is a very lon…"
