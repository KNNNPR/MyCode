let trashCan = [];
var summPrice = 0;
let startArray = [];
      
          function addElement() {
            const element = {
              name: `Purchase ${Math.floor(Math.random() * 1000)}`,
              price: Math.floor(Math.random() * 100)
            };
            summPrice+=element.price;
            trashCan.push(element);
            startArray.push(element);
            renewTrashCan();
          }
      
          function makeTrashCanEmpty() {
            trashCan = [];
            startArray = [];
            summPrice = 0;
            renewTrashCan();
          }
      
          function sortGreater() {
            trashCan.sort((a, b) => a.price - b.price);
            renewTrashCan();
          }
      
          function sortLower() {
            trashCan.sort((a, b) => b.price - a.price);
            renewTrashCan();
          }
      
          function filter() {
            startArray = [...trashCan];
            const a = parseFloat(prompt('Введите минимальную цену:', '0'));
            const b = parseFloat(prompt('Введите максимальную цену:', '100'));
      
            if (!isNaN(a) && !isNaN(b)) {
              const filtred = trashCan.filter(element => element.price > a && element.price < b);
              const trashCanHTML = filtred.map(element => `<div class="token">${element.name} - ${element.price}</div>`).join('');
              document.getElementById('корзина').innerHTML = trashCanHTML;
              trashCan = filtred;
            } else {
              alert('Пожалуйста, введите числовые значения для фильтрации.');
            }
          }
      
          function denySort() {
            trashCan = [...startArray];
            renewTrashCan();
          }
      
          function renewTrashCan() {
            const trashCanHTML = trashCan.map(element => `<div class="token">${element.name}, price: ${element.price}</div>`).join('');
            document.getElementById('корзина').innerHTML = trashCanHTML;
            document.getElementById('summPrice').textContent = 'total price: ' + summPrice;
          }
          
          function deleteLast() {
            summPrice = summPrice - trashCan.pop().price;
            renewTrashCan();
          }