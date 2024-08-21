import Header from './Header.jsx';
import Footer from './Footer.jsx';
import Food from './Food.jsx';
import Card from './Card.jsx';
// MODULE METHOD CSS
import Button from './Button/Button.jsx';

import Student from './Student.jsx';
import UserGreeting from './User.jsx';

function App() {
  // return (
  //   <>
  //     <Header/>
  //     <Food/>
  //     <Food/>
  //     <Footer/>
  //   </>
  // );  
  // return(
  //   <>
  //     {/* <Card/>
  //     <Card/> */}
  //     <Button/>
  //   </>
  // );

  // return (
  //   <>
  //     <Student name='Marcos' age={23} isStudent = {true}/>
  //     <Student name='Luis' age={25} isStudent = {false}/>
  //     <Student/>
  //   </>
  // );

  return (
    <>
      <UserGreeting isLoggedIn={true} username='Marcos'/>
      <UserGreeting isLoggedIn={false} username='Marta'/>
      <UserGreeting />
    </>
  )
}

export default App
