import './App.css'


function Test(props) {

    return (
        <>
            <p>Ceci est un paragraphe.</p>
            <p>Et voilà ton text mon gars:</p>
            <p>{props.text}</p>
        </>
        
    )
}

export default Test