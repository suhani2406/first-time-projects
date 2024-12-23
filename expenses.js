// Get DOM elements
const expenseForm = document.getElementById('expense-form');
const expenseList = document.getElementById('expense-list');
const totalAmount = document.getElementById('total-amount');

// Array to store expenses
let expenses = [];

// Function to update total expenses
function updateTotal() {
    const total = expenses.reduce((sum, expense) => sum + expense.amount, 0);
    totalAmount.textContent = total.toFixed(2);
}

// Function to display expenses
function displayExpenses() {
    expenseList.innerHTML = '';

    expenses.forEach((expense, index) => {
        const li = document.createElement('li');
        li.innerHTML = `
            ${expense.name} - $${expense.amount.toFixed(2)}
            <button class="delete-btn" data-index="${index}">Delete</button>
        `;
        expenseList.appendChild(li);
    });
}

// Function to handle form submit
expenseForm.addEventListener('submit', function (e) {
    e.preventDefault();

    const name = document.getElementById('expense-name').value;
    const amount = parseFloat(document.getElementById('expense-amount').value);

    if (name && amount) {
        expenses.push({ name, amount });
        displayExpenses();
        updateTotal();

        // Clear input fields
        expenseForm.reset();
    }
});

// Function to handle delete button click
expenseList.addEventListener('click', function (e) {
    if (e.target.classList.contains('delete-btn')) {
        const index = e.target.getAttribute('data-index');
        expenses.splice(index, 1);
        displayExpenses();
        updateTotal();
    }
});
