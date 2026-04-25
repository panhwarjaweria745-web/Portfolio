const menuIcon = document.querySelector("#menu-icon");
const navLinks = document.querySelector(".nav-links");

menuIcon.onclick = () => {
    navLinks.classList.toggle("active");
};
function showContact() {
    const box = document.getElementById("contact-box");
    if (!box) return; // safety

    box.style.display = (box.style.display === "block") ? "none" : "block";
}