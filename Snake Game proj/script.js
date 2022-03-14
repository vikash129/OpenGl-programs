let speed = 1
let lastPaintTime = 0

let snakeArr = [
    { x: 4, y: 5 },
    { x: 5, y: 5 }]


let inputDir = { x: 0, y: 0 }

let foodSound = new Audio('sounds/snakeatt.mp3')
let gameOverSound = new Audio('sounds/snakehit.mp3')
let moveSound = new Audio('sounds/snakehiss.mp3')
let musicSound = new Audio('sounds/snakehit2.wav');

let screen = { 'row': 18, 'column': 18 }

function randomFoodPost() {
    x = Math.round(Math.random() * 2 + (18 - 2))
    y = Math.round(Math.random() * 2 + (18 - 2))
    print(x, y)

    return { 'x': x, 'y': y }
}

let food = randomFoodPost()


// //eating food cond
function ifFoodEat() {

    if (snakeArr[0].y === food.y && snakeArr[0].x === food.x) {
        snakeArr.unshift({ x: snakeArr[0].x + inputDir.x, y: snakeArr[0].y + inputDir.y })
        // speed += 
        food = randomFoodPost()

    }
}

function isCollide(snake) {
    for (let i = 1; i < snakeArr.length; i++) {
        if (snake[i].x === snake[0].x && snakeArr[i].x === snakeArr[0].x) {
            return true
        }
        // else if (snake[0].x >= screen.column || snake[0].x <= 0 || snake[0].y <= 0 || snake[0].y >= screen.row) {
        //     return true
        // }
    }
    return false
}

function gameOver() {
    // gameOverSound.play()
    // musicSound.pause()
    inputDir = { x: 0, y: 0 }
    alert('game pver')
    // musicSound.play()
    score = 0
    let snakeArr = [
        { x: 13, y: 15 },
        { x: 5, y: 5 }]
}


// //main loop
function main(ctime) {
    // window.requestAnimationFrame(main)
    // console.log(ctime)

    if ((ctime - lastPaintTime) / 1000 < 1 / speed) {
        return;
    }
    lastPaintTime = ctime
    gameEngine()
}


// //game engine
function gameEngine() {

    // 1 update smake array and food
    // snakeArr[0].x += inputDir.x
    // snakeArr[0].y += inputDir.y

    // //moving the snake
    // for (let i = snakeArr.length - 2; i >= 0; i++) {
    //     const element = snakeArr[i]
    //     snakeArr[i + 1] = { ...snakeArr[i] }
    // }


    //2 display the snake 
    let board = document.getElementById('board')

   

    let snakeElement = document.createElement('div')

    snakeArr.forEach((e, index) => {

        snakeElement.style.gridRowStart = e.y
        snakeElement.style.gridColumnStart = e.x


        if (index === 0) {
            snakeElement.classList.add = 'head'
        }
        else {
            snakeElement.classList.add = 'snake'
        }
        board.appendChild(snakeElement)
    });

    //display the food
    let foodElement = document.createElement('div')

    foodElement.style.gridRowStart = food.y
    foodElement.style.gridColumnStart = food.x
    foodElement.classList.add('food')

    board.appendChild(foodElement)


    //3 checking condintiona

    //check game over situation 
    // if (isCollide(snakeArr)) {
    //     gameOver()
    // }

    // //check food
    // ifFoodEat()

}



window.requestAnimationFrame(main)


// controls
window.addEventListener('keydown', e => {
    inputDir = { x: 0, y: 1 }
console.log(e.key)
    switch (e.key) {

        case 'w':
            inputDir.y = 1
            inputDir.x = 0

        case 's':
            inputDir.y = -1
            inputDir.x = 0

        case 'a':
            inputDir.x = -1
            inputDir.y = 0


        case 'd':
            inputDir.x = 1
            inputDir.y = 0


        case 'e':
            inputDir.x = 0
            inputDir.y = 0

        default:
            break

    }
})