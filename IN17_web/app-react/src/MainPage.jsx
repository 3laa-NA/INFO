import { useState } from 'react'
import NavigationPanel from './NavigationPanel'
import './App.css'

function MainPage() {
    const [pageState, setPageState] = useState({
        currentPage: 'signin_page',
        isConnected: false
    })

    const getConnected = () => {
        setPageState({
            currentPage: 'message_page',
            isConnected: true
        })
    }

    const setLogout = () => {
        setPageState({
            currentPage: 'signin_page',
            isConnected: false
        })
    }

    return (
        <div>
            <NavigationPanel 
                login={getConnected} 
                logout={setLogout} 
                isConnected={pageState.isConnected} 
            />
            <main>
                {/* Le contenu principal sera ajouté ici plus tard */}
            </main>
        </div>
    )
}

export default MainPage
