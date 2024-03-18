function createListItem() {
    const list = document.getElementsByClassName('notificationList');
    const listItem = document.createElement('li');
    listItem.textContent = 'notif';
    list.appendChild(listItem);
    createListItem();
  }

  createListItem();