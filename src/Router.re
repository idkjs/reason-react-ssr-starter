/* App is the actual entry point for the application. It matches on the route prop to determine which
   sub-component to render */

[@react.component]
let make = (~serverUrl: option(ReasonReactRouter.url)) => {
  let url =
    switch (serverUrl) {
    | Some(url) => url
    | None => ReasonReactRouter.useUrl()
    };
  // let url = ReasonReactRouter.useUrl(~serverUrl, ());
  let route = Routes.match(url);

  <div className="app">
    <HeaderNav />
    {switch (route) {
     | Home => <Home />
     | About => <About />
     | NotFound =>
       <div> "404 - Route Not Found :("->React.string </div>
     }}
  </div>;
};