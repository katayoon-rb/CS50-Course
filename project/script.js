// ham menu

const hamMenuContainer = document.querySelector('.ham-menu-container') 
const hamIcon = document.getElementById('line-con')
const options = document.querySelectorAll('option')


hamIcon.addEventListener("click", () => {
    hamMenuContainer.classList.remove("still")
    hamIcon.classList.remove("still")
    options.forEach(option => {
        option.classList.remove("still")
    })
    
	hamIcon.classList.toggle('close')
    hamMenuContainer.classList.toggle('visible')
    hamMenuContainer.classList.toggle('invisible')
})


// half-img overlay

const halfImgs = document.querySelectorAll('.half-img')

halfImgs.forEach(halfImg => {
    if (halfImg.childNodes[1].classList == 'hover') {
        halfImg.addEventListener('mouseenter', () => {
            halfImg.childNodes[1].style.visibility = 'visible'
        })
        halfImg.addEventListener('mouseleave', () => {
            halfImg.childNodes[1].style.visibility = 'hidden'
        })
    }
})


// preview popup

const learns = document.querySelectorAll('#learn')
const closeBtn = document.querySelector('.fa-xmark')
const preview = document.querySelector('.preview')

learns.forEach(learn => {
    learn.addEventListener('click', () => {
        preview.classList.add('active')
        document.querySelector('.title').innerText = learn.parentElement.childNodes[1].firstChild.data

        if (learn.parentElement.parentElement.classList[1] == 'line1') {
            document.querySelector('.image').style.backgroundImage = 'url("images/desktop/image-transform.jpg")'
        }
        else if (learn.parentElement.parentElement.classList[1] == 'line2') {
            document.querySelector('.image').style.backgroundImage = 'url("images/desktop/image-stand-out.jpg")'
        }
    })
})
    
closeBtn.addEventListener('click', () => {
    preview.classList.remove('active')
})