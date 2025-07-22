const input = document.querySelector(".text");
const button   = document.querySelector(".add");
const content = document.querySelector(".content");

 button.addEventListener("click",()=>{
 let value = input.value.trim();
 if(value === '') return;

let flexRow = document.createElement("div");
 flexRow.classList.add("row");

  let taskText = document.createElement("div");
  taskText.textContent = value;
  taskText.classList.add("task");
  
 let del = document.createElement("div");
  del.textContent = 'Delete';
 del.classList.add("del");
  del.addEventListener("click",()=>{
  flexRow.remove() });

  flexRow.appendChild(taskText);
  flexRow.appendChild(del);

  content.appendChild(flexRow);
  input.value = '';
});
