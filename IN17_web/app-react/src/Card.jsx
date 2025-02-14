import { useState } from 'react'
import './App.css'

function Card(props) {
    const [affichage, setAffichage] = useState(props.affichage)

    function clicked(){
        setAffichage("visible")
    }

    return (
        <>
            <div className='Cards' onClick={clicked}>{affichage==="visible"?props.symbol:"."}</div>
        </>
    )
}

export default Card